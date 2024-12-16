cmake_minimum_required(VERSION 3.5)
project(CompositionStringUnderline)
SET(SOURCE_FILES ./Compartment.cpp 
./Composition.cpp 
./DisplayAttribute.cpp 
./DisplayAttributeInfo.cpp 
./DisplayAttributeProvider.cpp
./DllMain.cpp
./EndComposition.cpp 
./EnumDisplayAttributeInfo.cpp
./Globals.cpp 
./KeyEventSink.cpp
./KeyHandler.cpp 
./LanguageBar.cpp 
./PreComp.cpp 
./Register.cpp
./Server.cpp
./TextEditSink.cpp
./TextService.cpp 
./TextService.def 
./TextService.rc 
./ThreadMgrEventSink.cpp)
add_library(CompositionStringUnderline SHARED ${SOURCE_FILES})