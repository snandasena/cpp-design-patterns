cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(Boost 1.67.0 REQUIRED)

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
add_executable(design_patterns structural/composite_pattern01.cpp)