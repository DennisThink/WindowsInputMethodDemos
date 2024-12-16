cmake_minimum_required(VERSION 3.0)
project(PropertyMonitor)
SET(SOURCE_FILES 
./DllMain.cpp 
./DumpProperties.cpp
./Globals.cpp 
./LanguageBar.cpp 
./MemoryStream.cpp
./PopupWindow.cpp
./PreComp.cpp
./Register.cpp 
./Server.cpp 
./TextEditSink.cpp 
./TextService.cpp
./ThreadFocusSink.cpp
./TsfPropertyMonitor.def
./TsfPropertyMonitor.rc
./ThreadMgrEventSink.cpp)
add_library(PropertyMonitor SHARED ${SOURCE_FILES})