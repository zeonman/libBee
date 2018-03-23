cmake_minimum_required(VERSION 3.0)
project(libBee)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(BEE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

if(MSVC)
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif(MSVC)

include_directories(${BEE_INCLUDE_PATH})

add_subdirectory(library/data_structure ${PROJECT_BINARY_DIR}/data_structure)