cmake_minimum_required(VERSION 3.0)
project(TrackFocus)
SET(SOURCE_FILES 
./DllMain.cpp 
./Globals.cpp 
./PreComp.cpp
./Register.cpp 
./Server.cpp 
./TextService.cpp
./TextService.def
./TextService.rc
./ThreadMgrEventSink.cpp)
add_library(TrackFocus SHARED ${SOURCE_FILES})