echo compiling Playback
g++ -lasound AudioInterface.cpp mainPlayback.cpp -o playback

echo Compiling Record
g++ -lasound AudioInterface.cpp mainRecord.cpp -o record

echo compiling Loopback
g++ -lasound AudioInterface.cpp mainLoopback.cpp -o loopback

