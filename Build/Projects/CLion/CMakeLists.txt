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
include_directories(../../Source)
include_directories(../../Source/Signals)
include_directories(../../Source/Neurons)
include_directories(../../Source/Neurons/Connections)

#Manual include source files
set(NEURONSOURCE ../../Source/Neurons/BasicNeuron.cpp ../../Source/Neurons/Connections/Connection.cpp )

#Executable and location of Source (.cpp) files
add_executable(${PROJECT_NAME} ../../Source/main.cpp ${NEURONSOURCE})