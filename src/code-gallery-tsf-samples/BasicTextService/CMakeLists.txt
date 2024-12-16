cmake_minimum_required(VERSION 3.0)
project(BasicTextService)
SET(BASIC_TEXT_SERVICE_SOURCE_FILES ./DllMain.cpp ./Globals.cpp ./PreComp.cpp ./Register.cpp ./Server.cpp ./TextService.cpp ./TextService.rc)
add_library(BasicTextService SHARED ${BASIC_TEXT_SERVICE_SOURCE_FILES})