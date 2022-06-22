project(Parsers)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
        ${PROJECT_SOURCE_DIR}/include/parsers/JsonParser.h
        ${PROJECT_SOURCE_DIR}/include/parsers/XmlParser.h
        ${PROJECT_SOURCE_DIR}/include/parsers/ParsersFactory.h
        ${PROJECT_SOURCE_DIR}/include/parsers/ValidatedReportParser.h
        )


set(SOURCES
        ${PROJECT_SOURCE_DIR}/src/JsonParser.cpp
        ${PROJECT_SOURCE_DIR}/src/ParsersFactory.cpp
        ${PROJECT_SOURCE_DIR}/src/XmlParser.cpp
        ${PROJECT_SOURCE_DIR}/src/ValidatedReportParser.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE
        Common
        External
        Interfaces)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)