#CMake version needed
cmake_minimum_required(VERSION 3.12)

#Project Name - CPPANN
project(CPPANN)

#CMake C++ Standard
set(CMAKE_CXX_STANDARD 17)

#Set version number
set(CPPANN_VERSION_MAJOR 1)
set(CPPANN_VERSION_MINOR 0)

#Header files
include_directories(source/signals)
include_directories(source/neurons)
include_directories(source/neurons/connections)

#Manual include source files
set(NEURONSOURCE source/neurons/BasicNeuron.cpp)

#Executable and location of Source (.cpp) files
add_executable(${PROJECT_NAME} source/main.cpp ${NEURONSOURCE})