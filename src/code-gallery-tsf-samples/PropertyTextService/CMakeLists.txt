cmake_minimum_required(VERSION 3.0)
project(PropertyTextService)
SET(SOURCE_FILES 
./CustomProperty.cpp
./CustomPropertyStore.cpp
./DllMain.cpp 
./Globals.cpp 
./LanguageBar.cpp 
./PreComp.cpp
./PropertyTextService.def
./PropertyTextService.rc
./Register.cpp 
./Server.cpp 
./StaticCompactProperty.cpp 
./TextEditSink.cpp 
./TextService.cpp
./ThreadMgrEventSink.cpp)
add_library(PropertyTextService SHARED ${SOURCE_FILES})