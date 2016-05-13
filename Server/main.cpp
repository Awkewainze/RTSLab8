#include <iostream>

using namespace std;
// Computer
// Display video
// On Qt gui
// Play sound
// From network
#include "NetworkListener.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "Player.h"

// run with 'avserver <audio playback hardware> <audio port> <video port>'
int main(int argc, char* argv[]) {


    //create audio thread
    //create video thread
}

void runAudio(char* port){
    AudioPlayer player("plughw:1");
    NetworkListener audioListener(port, player);

    audioListener.getDataFromClient();
}

void runVideo(char* port){

}