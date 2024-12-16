cmake_minimum_required(VERSION 3.0)
project(Keyboard)
SET(SOURCE_FILES ./Compartment.cpp 
./DllMain.cpp 
./Globals.cpp 
./KeyEventSink.cpp 
./LanguageBar.cpp 
./PreComp.cpp 
./Register.cpp 
./Server.cpp 
./TextEditSink.cpp 
./TextService.cpp
./TextService.def
./TextService.rc
./ThreadMgrEventSink.cpp)
add_library(Keyboard SHARED ${SOURCE_FILES})