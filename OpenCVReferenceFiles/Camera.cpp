#include "Camera.h"

Camera::Camera(int port, int pinNumber, int width, int height) {
    light = new GPIO(pinNumber);
    light->setDirection(GPIO::OUTPUT);
    capture = new VideoCapture(port);
    this->height = height;
    this->width = width;
    capture->set(CV_CAP_PROP_FRAME_HEIGHT, height);
    capture->set(CV_CAP_PROP_FRAME_WIDTH, width);
    cout << "Setting resolution to " + to_string(width) + "x" + to_string(height) << endl;
    running = true;
}

Camera::Camera(Camera &c) {
    // Not sure if this is what is wanted
    capture = c.capture;
    light = c.light;
    height = c.height;
    width = c.width;
    running = c.running;
}

Camera::~Camera() {
    delete capture;
    delete light;
}

void Camera::run() {
    while(running){
        mutex_.lock();
        capture->grab();
        mutex_.unlock();
    }
}

void Camera::shutdown() {
    running = false;
    light->setValue(GPIO::LOW);
    cameraThread.join();
}

void Camera::start() {
    cameraThread = thread(&Camera::run, this);
}

void Camera::takePicture(int pictureType, int number) {
    mutex_.lock();
    struct timespec capture_begin, capture_end, write_begin, write_end;
    Mat frame;

    light->setValue(GPIO::HIGH);
    clock_gettime( CLOCK_REALTIME, &capture_begin );
    capture->retrieve(frame, 0);
    clock_gettime( CLOCK_REALTIME, &capture_end );

    double capture_time_secs = (capture_end.tv_sec - capture_begin.tv_sec) + (double)(capture_end.tv_nsec - capture_begin.tv_nsec)/1000000000.0;
    cout << "Capture time: " << capture_time_secs << " secs" << endl;
    clock_gettime( CLOCK_REALTIME, &write_begin);
    if(pictureType == 1){
        const string image_name = "pic_" + to_string(number) + ".jpg";
        imwrite(image_name, frame);
        cout << image_name << endl;
    } else if (pictureType == 0){
        const string image_name = "pic_" + to_string(number) + ".png";
        imwrite(image_name, frame);
        cout << image_name << endl;
    } else {
        cerr << "Couldn't write selected file type";
        exit(-1);
    }
    clock_gettime( CLOCK_REALTIME, &write_end);

    double write_time_secs = (write_end.tv_sec - write_begin.tv_sec) + (double)(write_end.tv_nsec - write_begin.tv_nsec)/1000000000.0;
    cout << "Write time: " << write_time_secs << " secs" << endl;

    light->setValue(GPIO::LOW);
    mutex_.unlock();

}













