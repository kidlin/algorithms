cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

include_directories(
        ${PROJECT_SOURCE_DIR}/src)

add_executable(testAll main.cpp)
target_link_libraries(testAll ${CMAKE_THREAD_LIBS_INIT})