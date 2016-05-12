cmake_minimum_required(VERSION 3.5)
project(Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NetworkListener.cpp NetworkListener.h Player.cpp Player.h AudioPlayer.cpp AudioPlayer.h VideoPlayer.cpp VideoPlayer.h)
add_executable(Server ${SOURCE_FILES})