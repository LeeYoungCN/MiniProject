aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CODE_SRCS)
target_sources(${TARGET} PRIVATE ${CODE_SRCS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
