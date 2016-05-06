
#include "AudioInterface.h"

#define SAMPLING_RATE (11025)
#define NUMBER_OF_CHANNELS (2)
#define BYTES_PER_SAMPLE (2)
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
    AudioInterface *ai_capture;
    AudioInterface *ai_playback;
	int rc;
	char *buffer;
	int bufferSize;
	int secondsToCapture;

	if (argc !=3 ) {
		printf("Usage: %s <playback device (i.e. plughw:1)>  <Length>",
			   argv[0]);
		exit(0);
	}

    secondsToCapture = atoi(argv[2]);

    ai_capture = new AudioInterface(argv[1], SAMPLING_RATE, NUMBER_OF_CHANNELS, SND_PCM_STREAM_CAPTURE);
    ai_playback = new AudioInterface(argv[1], SAMPLING_RATE, NUMBER_OF_CHANNELS, SND_PCM_STREAM_PLAYBACK);
    ai_capture->open();
    ai_playback->open();

    bufferSize = ai_capture->getRequiredBufferSize();

    buffer = (char*)malloc(bufferSize);

    rc = 1;

    // Determine how many bytes need to be captured.
    int bytesToCapture = SAMPLING_RATE * secondsToCapture * NUMBER_OF_CHANNELS * BYTES_PER_SAMPLE;

	for(int i = 0; i < 10;i++){
          memset(buffer, 0, bufferSize);
	  ai_playback->write(buffer,bufferSize);
       }
    do {
        memset(buffer, 0, bufferSize);

        // Capture from the soundcard

        rc = ai_capture->read(buffer);
        ai_playback->write(buffer, bufferSize);
        bytesToCapture-=bufferSize;

    } while ((bytesToCapture > 0)&&(rc>0));

    ai_capture->close();
    ai_playback->close();
    free(buffer);
    return 0;
}
