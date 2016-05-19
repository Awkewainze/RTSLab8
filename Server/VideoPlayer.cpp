//
// Created by Kevin Linsley on 5/12/16.
//

#include "VideoPlayer.h"
#include <QtGui>

#include "VideoPlayer.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

/*
 *Creates the main window for the GUI.
 */
VideoPlayer::VideoPlayer()
{
    image_width = 100;
    image_height = 100;
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    layout = new QVBoxLayout;
    layout->addWidget(scrollArea);

    QWidget* layoutWidget = new QWidget(this);
    layoutWidget->setLayout(layout);
    setCentralWidget(layoutWidget);

    createActions();
    setWindowTitle(tr("Image Viewer"));
    resize(500, 400);
}

/*
 * Slot handling the speak button
 */
void VideoPlayer::speak()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    QString qcmd = "espeak -w time.wav \"" + text + "\"";
    QByteArray ba = qcmd.toLatin1();
    const char *cmd = ba.data();
    system(cmd);
    qcmd = "mplayer time.wav";
    ba = qcmd.toLatin1();
    cmd = ba.data();
    system(cmd);

}

//Draws the image on the screen
void VideoPlayer::print()
{
    Q_ASSERT(imageLabel->pixmap());
#ifndef QT_NO_PRINTER
    QPrintDialog dialog(&printer, this);
    if (dialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = imageLabel->pixmap()->size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(imageLabel->pixmap()->rect());
        painter.drawPixmap(0, 0, *imageLabel->pixmap());
    }
#endif
}

//Came from QT tutorial linked in lab pdf

void VideoPlayer::zoomIn()
{
    scaleImage(1.25);
}

//Came from QT tutorial linked in lab pdf

void VideoPlayer::zoomOut()
{
    scaleImage(0.8);
}

//Came from QT tutorial linked in lab pdf

void VideoPlayer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

//Came from QT tutorial linked in lab pdf
void VideoPlayer::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        normalSize();
    }
    updateActions();
}

//Came from QT tutorial linked in lab pdf
//Creates the actions and links the signals to slots for the menu bar
void VideoPlayer::createActions()
{
    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcut(tr("Ctrl+P"));
    printAct->setEnabled(false);
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
    zoomInAct->setShortcut(tr("Ctrl++"));
    zoomInAct->setEnabled(false);
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
    zoomOutAct->setShortcut(tr("Ctrl+-"));
    zoomOutAct->setEnabled(false);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

    normalSizeAct = new QAction(tr("&Normal Size"), this);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(false);
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

    fitToWindowAct = new QAction(tr("&Fit to Window"), this);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));
    connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));
}

//Came from QT tutorial linked in lab pdf
void VideoPlayer::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

//Came from QT tutorial linked in lab pdf
void VideoPlayer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

//Came from QT tutorial linked in lab pdf
void VideoPlayer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void VideoPlayer::play(char* source, int length){

    QPixmap pixmap = QPixmap::fromImage(
            QImage(
                    (unsigned char *) source,
                    image_width,
                    image_height,
                    QImage::Format_RGB888
            )
    );
    imageLabel->setPixmap(pixmap);
    scaleFactor = 1.0;

    printAct->setEnabled(true);
    fitToWindowAct->setEnabled(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
        imageLabel->adjustSize();



}
