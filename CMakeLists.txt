cmake_minimum_required(VERSION 4.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
project(LightMania VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(extern/SDL EXCLUDE_FROM_ALL)


find_package(SQLite3 REQUIRED)

add_executable(LightMania ./src/main.c)

target_link_libraries(LightMania 
    SDL3::SDL3
    SQLite3::SQLite3
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
