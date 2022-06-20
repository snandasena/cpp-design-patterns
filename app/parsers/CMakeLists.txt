project(Parsers)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
        ${PROJECT_SOURCE_DIR}/include/parsers/JsonParser.h
        )


set(SOURCES
        ${PROJECT_SOURCE_DIR}/src/JsonParser.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
