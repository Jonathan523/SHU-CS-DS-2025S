cmake_minimum_required(VERSION 3.10)
project(DS LANGUAGES CXX VERSION 0.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_GENERATOR "Ninja")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
message("CMAKE_SYSTEM_NAME:      ${CMAKE_SYSTEM_NAME}")
message("CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message("CMAKE_CXX_COMPILER_ID:  ${CMAKE_CXX_COMPILER_ID}")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("GCC on Windows Detected. Added GBK charset for GCC & G++")
    add_compile_options(-fexec-charset=GBK)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DS_DEBUG)
    add_compile_options(-DDS_Debug)
else()
    add_compile_definitions(DS_RELEASE)
    add_compile_options(-DDS_RELEASE)
endif()

add_subdirectory(chapter7)
add_subdirectory(chapter8)