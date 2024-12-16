cmake_minimum_required(VERSION 3.0)
project(TextInsertion)
SET(SOURCE_FILES 
./DllMain.cpp 
./Globals.cpp 
./InsertHello.cpp 
./LanguageBar.cpp
./PreComp.cpp
./Register.cpp 
./Server.cpp 
./TextEditSink.cpp 
./TextService.cpp
./TextService.def 
./TextSErvice.rc
./ThreadMgrEventSink.cpp)
add_library(TextInsertion SHARED ${SOURCE_FILES})