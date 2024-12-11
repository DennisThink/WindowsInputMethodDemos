cmake_minimum_required(VERSION 3.0)
project(WinInputMethodDemo1)
SET(SOURCE_FILE ./DllMain.cpp ./Log.cpp)
add_library(WinInputDemoOne SHARED  ${SOURCE_FILE})