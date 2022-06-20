project(Common)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
        ${PROJECT_SOURCE_DIR}/include/constants/Constants.h
        ${PROJECT_SOURCE_DIR}/include/types/Report.h
        ${PROJECT_SOURCE_DIR}/include/types/ReportFormat.h
        ${PROJECT_SOURCE_DIR}/include/types/User.h
        )