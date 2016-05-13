#include <iostream>
#include "NetworkSender.h"
#include "AudioRecorder.h"
#include<thread>
using namespace std;
// Receive sound from microphone (or file)
// Calculate volume
// Take video capture
// Send to server

// run with 'avclient <audio capture device> <destination hostname> <destination audio port> <destination video port> <length of time to send in seconds>'
int main(int argc, char*argv[]) {
    cout << "Hello, World!" << endl;
    AudioRecorder recorder = new Recorder(argv[1],argv[2]);
    recorder->start();
    std::thread thread = recorder.getThread();
    thread->join();
    return 0;
}
