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
void runAudio(char *device,int duration,char*ip,char *port){
	NetworkSender *sender = new NetworkSender(ip,port);
	AudioRecorder recorder(device,duration,sender);
	recorder.record();
}
void runVideo(char* ip, char *port){
	NetworkSender *sender = new NetworkSender(ip,port);
	VideoRecorder recorder(240,160,sender);
	recorder.record();
}
int main(int argc, char*argv[]) {


    if(argc != 5)
    {
        cout << "Needs <hardware device> <server audio port> <server video port> <Length of record time> " << endl;
        exit(-1);
    }
    char *ip = "";

    std::thread audioThread(runAudio,argv[1],atoi(argv[4]),ip,argv[2]);
    std::thread videoThread(runVideo,ip,argv[3]);

    audioThread.join();
    videoThread.join();

    return 0;
}
