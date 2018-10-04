
cmake_minimum_required(VERSION 3.12)
project(CPPANN)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} source/main.cpp source/neurons/BasicNeuron.cpp source/neurons/BasicNeuron.h)