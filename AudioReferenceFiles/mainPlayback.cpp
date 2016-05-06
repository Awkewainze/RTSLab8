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
 * @param argc This is the number of arguments passed in.  Must be 3 for the program to work.
 * @param argv These are the arguments passed in.
 * @return
 */
int main(int argc, char* argv[])
{
	AudioInterface *ai;
	int rc;
	char *buffer;
	int bufferSize;

	// Check to make certain the argument6 length is correct and usable.
	if (argc != 3) {
		printf("Usage: %s <playback device (i.e. plughw:1)> <File to playback>",
				argv[0]);
		exit(0);
	}
	// Instantiate and open a new audio interface.
	ai = new AudioInterface(argv[1], SAMPLING_RATE, NUMBER_OF_CHANNELS, SND_PCM_STREAM_PLAYBACK);
	ai->open();
	bufferSize = ai->getRequiredBufferSize();

	buffer = (char*)malloc(bufferSize);

	// Open the file that is going to be read.
	int filedesc = open(argv[2], O_RDONLY);
	rc = 1;

	do {
		// Read from the file.
		rc = read(filedesc, buffer, bufferSize);

		if (rc > 0) {
			ai->write(buffer, rc);
		}
	} while (rc > 0);

	ai->close();
	return 0;
}
