/**
 *Application playback
 * This program will play back a given audio file using the AudioInterface class.
 * @author Walter Schilling
 * @date April, 2015
  */

#include "AudioInterface.h"

#define SAMPLING_RATE (22500)
#define NUMBER_OF_CHANNELS (2)
#define BYTES_PER_SAMPLE (2)

/**
 * This is the main method of the program.
 * @param argc This is the number of arguments passed in.  Must be 4 for the program to work.
 * @param argv These are the arguments passed in.
 * @return
 */
int main(int argc, char* argv[])
{
	AudioInterface *ai;
	int rc;
	char *buffer;
	int bufferSize;
	int secondsToCapture;

	// Check to make certain the argument6 length is correct and usable.
	if (argc != 4) {
		printf("Usage: %s <playback device (i.e. plughw:1)> <File to record> <Length>",
				argv[0]);
		exit(0);
	}

	secondsToCapture = atoi(argv[3]);

	ai = new AudioInterface(argv[1], SAMPLING_RATE, NUMBER_OF_CHANNELS, SND_PCM_STREAM_CAPTURE);
	ai->open();
	bufferSize = ai->getRequiredBufferSize();

	buffer = (char*)malloc(bufferSize);

	// Open the file that is going to be read.
	int filedesc = open(argv[2], O_WRONLY | O_CREAT);
	rc = 1;

	// Determine how many bytes need to be captured.
	int bytesToCapture = SAMPLING_RATE * secondsToCapture * NUMBER_OF_CHANNELS * BYTES_PER_SAMPLE;

	do {
		// Fill the buffer with all zeros.
		memset(buffer, 0, bufferSize);

		// Capture from the soundcard
		ai->read(buffer);

		// Write to the file.
		rc = write(filedesc, buffer, bufferSize);

		bytesToCapture-=bufferSize;

	} while ((bytesToCapture > 0)&&(rc>0));
	close(filedesc);

	ai->close();
	return 0;
}
