cmake_minimum_required(VERSION 3.5)
project(IconInLanguageBar)
SET(SOURCE_FILES ./DllMain.cpp 
./Globals.cpp
./LanguageBar.cpp 
./PreComp.cpp 
./Register.cpp 
./Server.cpp 
./TextEditSink.cpp 
./TextService.cpp 
./TextService.def 
./TextService.rc 
./ThreadMgrEventSink.cpp)
add_library(IconInLanguageBar SHARED ${SOURCE_FILES})