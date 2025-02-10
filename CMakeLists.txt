cmake_minimum_required(VERSION 3.10)
project(VerletIntegration)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)

file(GLOB_RECURSE SOURCES "src/".cpp)

add_executable(VerletIntegration src/main.cpp)

target_link_libraries(VerletIntegration sfml-graphics sfml-window sfml-system)
