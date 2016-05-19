echo compiling Client
g++ -lasound -std=c++11 -w AudioRecorder.cpp NetworkSender.cpp VideoRecorder.cpp main.cpp -o avconferenceclient
