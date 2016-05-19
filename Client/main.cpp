#include <iostream>
#include "NetworkSender.h"
#include "AudioRecorder.h"
#include "VideoRecorder.h"
#include<thread>
using namespace std;
// Receive sound from microphone (or file)
// Calculate volume
// Take video capture
// Send to server

// run with 'avclient <audio capture device> <destination hostname> <destination audio port> <destination video port> <length of time to send in seconds>'
int main(int argc, char*argv[]) {


    if(argc != 5)
    {
        cout << "Needs <hardware device> <server audio port> <server video port> <Length of record time> " << endl;
        exit(-1);
    }
    NetworkSender *sender = new NetworkSender(argv[2],argv[3]);
    AudioRecorder audioRecorder(argv[1],atoi(argv[4]),sender);
    VideoRecorder videoRecorder(240,160,sender);

    std::thread audioThread (audioRecorder.record());
    std::thread videoThread (videoRecorder.record());

    audioThread.join();
    videoRecorder.stop();
    videoThread.join();

    return 0;
}
