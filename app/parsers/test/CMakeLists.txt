project(ParsersTests)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

set(SOURCES
        JsonParser_test.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
        GTest::GTest
        GTest::Main
        Interfaces
        External
        Common
        Parsers)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
