#include <iostream>
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
    VideoPlayer player();
    NetworkListener videoListener(port, player);

    videoListener.getDataFromClient();
}


// run with 'avserver <audio playback hardware> <audio port> <video port>'
int main(int argc, char* argv[]) {


    thread audio(runAudio, argv[1], argv[2]);
    thread video(runVideo, argv[3]);

    audio.join();
    video.join();

    return 0;
}