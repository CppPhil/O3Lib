cmake_minimum_required(VERSION 3.6)
project(O3Lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES main.cpp O3/detail/common.h O3/detail/compiler_detection.h O3/macros.h O3/nullptr.h O3/memory.h O3/except.h O3/iterator.h O3/algorithm.h O3/type_traits.h)
add_executable(O3Lib ${SOURCE_FILES})