cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 17)
FIND_PACKAGE(Boost 1.67.0 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -ggdb3 -Wall -Wextra")

add_definitions(-std=c++17)
add_definitions(-DCMAKE_BUILD_TYPE=Debug)

add_subdirectory(Udemy)

# creational
#add_executable(design_patterns main.cpp)
#add_executable(design_patterns  creational/abstract_factory.cpp)
#add_executable(design_patterns  creational/factory_method.cpp)
#add_executable(design_patterns  creational/prototype_pattern.cpp)
#add_executable(design_patterns  creational/singleton_pattern.cpp)
#add_executable(design_patterns  creational/singleton_pattern_improved.cpp)
#add_executable(design_patterns creational/singleton_pattern_improved_v.cpp)

# structural
#add_executable(design_patterns structural/adapter_pattern.cpp)
#add_executable(design_patterns structural/bridge_pattern.cpp)
#add_executable(design_patterns structural/composite_pattern01.cpp)
#add_executable(design_patterns structural/composite_pattern02.cpp)
#add_executable(design_patterns structural/decorator_pattern.cpp)