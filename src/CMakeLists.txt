cmake_minimum_required(VERSION 3.20)

# Activating C++ 11
set(CMAKE_CXX_STANDARD 11)
# Sets C++ 11 standard as required for compilers
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable compiler-specific C++ language extensions
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} exercise.cpp compute_score.cpp)
add_library(${PROJECT_NAME}_lib STATIC exercise.cpp compute_score.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
