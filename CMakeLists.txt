cmake_minimum_required(VERSION 3.17)
project(ArduinoNet)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(ArduinoNet
        include/Net.h
        include/NetComponent.h
        include/RadioInterface.h
        include/RF24Net.h
        include/RF24NetSleep.h
        include/SmartNet.h
        src/NetComponent.cpp
        src/RadioInterface.cpp
        src/RF24Net.cpp
        src/RF24NetSleep.cpp
        src/SmartNet.cpp)
