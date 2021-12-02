project(MiniProject)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
set(BUILDCACHE_PATH         ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/out)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)

set(CODE_PATH            ${CMAKE_SOURCE_DIR}/code)
set(GOOGLE_TEST_PATH    ${CMAKE_SOURCE_DIR}/lib/google_test)

set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

set(TARGET_NAME CppProgram)
set(GTEST_LIB_PATH ${GOOGLE_TEST_PATH}/lib)
include_directories(${GOOGLE_TEST_PATH}/inc)

add_executable(${TARGET_NAME})
add_subdirectory(${CODE_PATH})

file(GLOB GTEST_LIBS ${GTEST_LIB_PATH}/*.a)

target_link_libraries(${TARGET_NAME} ${GTEST_LIBS} pthread)
