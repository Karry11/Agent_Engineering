cmake_minimum_required(VERSION 3.25)
project(multi_thread)

set(CMAKE_CXX_STANDARD 17)

add_executable(multi_thread main.cpp SafeQueue.cpp SafeQueue.h test.cpp test.cpp)
