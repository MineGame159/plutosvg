cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_STANDARD 11)

project(plutojni C)

set(PLUTOJNI_SOURCE
    plutojni.h
    plutojni.c
)

add_library(plutojni SHARED ${PLUTOJNI_SOURCE})

target_link_libraries(plutojni PRIVATE plutosvg)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_include_directories(plutojni PRIVATE $ENV{JDK_HOME}/include)
    target_include_directories(plutojni PRIVATE $ENV{JDK_HOME}/include/win32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_include_directories(plutojni PRIVATE /usr/lib/jvm/default/include)
    target_include_directories(plutojni PRIVATE /usr/lib/jvm/default/include/linux)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_include_directories(plutojni PRIVATE $ENV{JDK_HOME}/include)
    target_include_directories(plutojni PRIVATE $ENV{JDK_HOME}/include/darwin)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()