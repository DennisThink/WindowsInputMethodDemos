cmake_minimum_required(VERSION 3.0)
project(TrackTextChange)
SET(SOURCE_FILES 
./DllMain.cpp 
./Globals.cpp 
./PreComp.cpp
./Register.cpp 
./Server.cpp 
./TextEditSink.cpp
./TextService.cpp
./TextService.def
./TextService.rc
./ThreadMgrEventSink.cpp)
add_library(TrackTextChange SHARED ${SOURCE_FILES})