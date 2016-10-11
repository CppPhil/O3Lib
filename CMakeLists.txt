cmake_minimum_required(VERSION 3.6)
project(O3Lib)

add_definitions(-DO3_NO_HASH_CONTAINERS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES main.cpp O3/common.h O3/compiler_detection.h O3/macros.h O3/nullptr.h O3/memory.h O3/except.h O3/iterator.h O3/algorithm.h O3/type_traits.h O3/assert.h O3/final_act.h O3/containers.h O3/noncopyable.h Catch/Catch.hpp O3/functional.h)
add_executable(O3Lib ${SOURCE_FILES})