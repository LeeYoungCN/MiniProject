project(mini_project)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_SOURCE_DIR}/cmake/toolchain.cmake)
set(GOOGLE_TEST_PATH        ${CMAKE_SOURCE_DIR}/google_test)
set(GTEST_LIB               ${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/output)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_INSTALL_PREFIX    ${CMAKE_SOURCE_DIR})
set(TARGET    Executable)
set(CMAKE_CXX_STANDARD 17)
set(CODE_PATH   ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(${TARGET})
add_subdirectory(${CODE_PATH})

link_directories(${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
target_include_directories(${TARGET} PRIVATE ${GOOGLE_TEST_PATH})

file(GLOB GTEST_LIBS ${GTEST_LIB}/*.a)
target_link_libraries(${TARGET} ${GTEST_LIBS} pthread)
