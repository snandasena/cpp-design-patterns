cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(Boost 1.67.0 REQUIRED)

#add_executable(design_patterns main.cpp)
#add_executable(design_patterns abstract_factory.cpp)
#add_executable(design_patterns factory_method.cpp)
#add_executable(design_patterns prototype_pattern.cpp)
#add_executable(design_patterns singleton_pattern.cpp)
#add_executable(design_patterns singleton_pattern_improved.cpp)
add_executable(design_patterns singleton_pattern_improved_v.cpp)