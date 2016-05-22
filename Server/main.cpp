#include <iostream>
#include <QApplication>
#include "NetworkListener.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "Player.h"
#include <thread>
#include "vidPlayer.h"

using namespace std;
// Computer
// Display video
// On Qt gui
// Play sound
// From network


void runAudio(char* audioDeviceName, char* port){
    AudioPlayer player(audioDeviceName);
    NetworkListener audioListener(port, &player);

    audioListener.getDataFromClient();
}

void runVideo(char* port, vidPlayer* p){
    NetworkListener videoListener(port, p);
    videoListener.getDataFromClient();

   // videoListener.getDataFromClient();
}


// run with 'avserver <audio playback hardware> <audio port> <video port>'
int main(int argc, char** argv) {
    QApplication *a = new QApplication(argc, argv);
    VideoPlayer player;
    vidPlayer p(&player);
    player.show();

//    thread audio(runAudio, argv[1], argv[2]);
    thread video(runVideo, argv[3], &p);

    a->exec();
//    audio.join();
    video.join();

    return 0;
}
