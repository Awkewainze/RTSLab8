#include <iostream>
#include "GPIO.h"
#include "Camera.h"
#include "pthread.h"
#include <mutex>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace exploringBB;

Camera* camera = NULL;

int button1Pressed(int var);
int button2Pressed(int var);
void SetupWaitForButton(int pin, CallbackType onEdge);

int picturesTaken = 0;

int main(int argc, char** argv) {
    int pngPin;
    int jpgPin;
    int ledPin;
    int height;
    int width;

    if(argc < 6 || argc > 6){
        cerr << "Error, expected input:" << endl << "Camera png_PinCode jpg_PinCode LED_PinCode image_width image_height" << endl;
        exit(-1);
    }
    ledPin = atoi(argv[3]);
    width = atoi(argv[4]);
    height = atoi(argv[5]);

    camera = new Camera(0, ledPin, width, height);

    pngPin = atoi(argv[1]);
    SetupWaitForButton(pngPin, button1Pressed);

    jpgPin = atoi(argv[2]);
    SetupWaitForButton(jpgPin, button2Pressed);

    camera->start();

    while(true){
        string input;
        cin >> input;
        if(input == "quit"){
            cout << "Exiting program" << endl;
            break;
        }
    }

    camera->shutdown();
    exit(0);
}

int button1Pressed(int button){
    camera->takePicture(0, picturesTaken);
    picturesTaken++;
}

int button2Pressed(int button){
    camera->takePicture(1, picturesTaken);
    picturesTaken++;
}

void SetupWaitForButton(int pin, CallbackType onEdge){
    GPIO* button1 = new GPIO(pin);
    button1->setDirection(GPIO::INPUT);
    button1->setEdgeType(GPIO::FALLING);
    button1->waitForEdge(onEdge);
}