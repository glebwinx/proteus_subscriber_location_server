cmake_minimum_required(VERSION 3.14)
project(<PROJECT-NAME>_SOURCE_DIR)

set(CMAKE_CXX_STANDART 14)

include(FetchContent)

FetchContent_Declare(
    spdlog
    URL https://github.com/gabime/spdlog/archive/v1.9.2.zip
)

FetchContent_GetProperties(spdlog)

if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

add_executable(locator locator.cpp)

target_link_libraries(locator PRIVATE spdlog::spdlog)