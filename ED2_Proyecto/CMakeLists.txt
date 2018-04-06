cmake_minimum_required(VERSION 3.9)
project(ED2_Proyecto)

set(CMAKE_CXX_STANDARD 11)

add_executable(ED2_Proyecto main.cpp Avl.cpp Avl.h structs.h DataFile.cpp DataFile.h ManejarAvl.cpp ManejarAvl.h RegistroRepetidos.h)