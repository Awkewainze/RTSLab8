//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_VIDEOPLAYER_H
#define SERVER_VIDEOPLAYER_H
#include "Player.h"
#include <QMainWindow>
#include <QPrinter>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QScrollArea>
#include <QScrollBar>
#include <QPrintDialog>

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class VideoPlayer : public QMainWindow, public Player{
    Q_OBJECT
public:
    VideoPlayer();
    void play(char* source, int length);
    int image_width;
    int image_height;
private slots:
    void print();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void speak();
private:
    void createActions();
    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;
    QVBoxLayout *layout;

#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif

    QAction *openAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

};

#endif
