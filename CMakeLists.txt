cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/include)

add_library(LA SHARED
        ${PROJECT_SOURCE_DIR}/src/sort.cpp)

add_executable(testAll main.cpp)
target_link_libraries(testAll LA)