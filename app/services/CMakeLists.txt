project(Services)

add_subdirectory(tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS
        ${PROJECT_SOURCE_DIR}/include/services/TaxService.h
        )

set(SOURCES
        ${PROJECT_SOURCE_DIR}/src/TaxServiceFactory.cpp
        ${PROJECT_SOURCE_DIR}/src/TaxService.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries( ${PROJECT_NAME} PRIVATE
        Interfaces
        Common
        Storage
        Servers
)