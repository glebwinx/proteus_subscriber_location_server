cmake_minimum_required(VERSION 3.14)
project(<PROJECT-NAME>)

set(CMAKE_CXX_STANDARD 14)  

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

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.1
)

FetchContent_GetProperties(nlohmann_json)

if (NOT nlohmann_json_POPULATED)
    FetchContent_Populate(nlohmann_json)
    add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR})
endif()

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_SOURCE_DIR})
endif()

add_executable(locator locator.cpp)

target_link_libraries(locator PRIVATE spdlog::spdlog nlohmann_json::nlohmann_json gtest_main)

#добавим тесты 
enable_testing()
add_executable(example example/example.cpp)

target_link_libraries(example PRIVATE gtest)
add_test(NAME MyTest COMMAND example)