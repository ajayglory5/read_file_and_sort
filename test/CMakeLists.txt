cmake_minimum_required(VERSION 3.20)

# Activating C++ 11
set(CMAKE_CXX_STANDARD 11)
# Sets C++ 11 standard as required for compilers
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable compiler-specific C++ language extensions
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}_test exercise_test.cpp)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME}_lib gtest gmock)
target_include_directories(${PROJECT_NAME}_test PUBLIC ${CMAKE_SOURCE_DIR}  )
