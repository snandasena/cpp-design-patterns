project(server)

set(CMAKE_CXX_FLAGS "-std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra -pedantic -Werror")

add_subdirectory(external)
add_subdirectory(common)
add_subdirectory(interfaces)
add_subdirectory(parsers)
add_subdirectory(configs)
add_subdirectory(auth)
add_subdirectory(servers)
add_subdirectory(services)
add_subdirectory(storage)