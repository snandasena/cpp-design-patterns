project(server)

set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -pedantic -Wall -Werror")

add_subdirectory(external)
add_subdirectory(common)
add_subdirectory(interfaces)
add_subdirectory(parsers)