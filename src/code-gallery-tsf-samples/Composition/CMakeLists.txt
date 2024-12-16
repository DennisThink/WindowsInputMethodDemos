cmake_minimum_required(VERSION 3.5)
project(Composition)
SET(SOURCE_FILES 
./Compartment.cpp 
./Composition.cpp
./DllMain.cpp
./EndComposition.cpp
./Globals.cpp
./KeyEventSink.cpp
./KeyHandler.cpp
./LanguageBar.cpp
./PreComp.cpp 
./Register.cpp
./Server.cpp 
./StartComposition.cpp 
TextEditSink.cpp 
./TextService.cpp 
./TextService.rc 
./ThreadMgrEventSink.cpp 
)

add_library(Composition SHARED ${SOURCE_FILES})