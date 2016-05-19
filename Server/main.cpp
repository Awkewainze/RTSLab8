#include <iostream>
#include <QApplication>
#include "NetworkListener.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "Player.h"
#include <thread>

using namespace std;
// Computer
// Display video
// On Qt gui
// Play sound
// From network

void runAudio(char* audioDeviceName, char* port){
    AudioPlayer player(audioDeviceName);
    NetworkListener audioListener(port, player);

    audioListener.getDataFromClient();
}

void runVideo(char* port){
    int argc = 0;
    char* argv[0];
    QApplication a(argc, argv);
    VideoPlayer player;
    player.show();
    NetworkListener videoListener(port, player);
    videoListener.getDataFromClient();
    a.exec();



   // videoListener.getDataFromClient();
}


// run with 'avserver <audio playback hardware> <audio port> <video port>'
int main(int argc, char** argv) {


    thread audio(runAudio, argv[1], argv[2]);
    thread video(runVideo, argv[3]);

    audio.join();
    video.join();

    return 0;
}
