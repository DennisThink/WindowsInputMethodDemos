cmake_minimum_required(VERSION 3.6)
project(CandidateList)
SET(CANDIDATE_LIST_SOURCE_FILES 
./CandidateList.cpp 
./CandidateWindow.cpp 
./Compartment.cpp 
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
./StartComposition.cpp 
./TextEditSink.cpp
./TextService.cpp 
./TextService.def 
./TextService.rc 
./ThreadMgrEventSink.cpp 
)
add_library(CandidateList SHARED ${CANDIDATE_LIST_SOURCE_FILES})