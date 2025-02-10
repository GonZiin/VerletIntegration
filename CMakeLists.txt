cmake_minimum_required(VERSION 3.10)
project(VerletIntegration)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

# Coleta todos os arquivos .cpp na pasta src/
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(VerletIntegration ${SOURCES})

target_link_libraries(VerletIntegration sfml-graphics sfml-window sfml-system)

