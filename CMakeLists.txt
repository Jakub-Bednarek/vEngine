cmake_minimum_required(VERSION 3.21s)
project(vEngine)

SET(CMAKE_CXX_STANDARD 20)

set(DEBUG_BUILD TRUE CACHE BOOL "Enable debug build")
set(FLY_BUILD FALSE CACHE BOOL "Enably fly build")
set(RELEASE_BUILD FALSE CACHE BOOL "Enable release build")

if(FLY_BUILD)
    add_compile_definitions(VFLY)
    message(STATUS "BUILD_TYPE=FLY")
elseif(RELEASE_BUILD)
    add_compile_definitions(VRELEASE)
    message(STATUS "BUILD_TYPE=RELEASE")
else()
    if(NOT ${DEBUG_BUILD})
        message(WARNING "Debug build type turned off, but none of the others selected. Defaulting to debug.")
    endif()
    message(STATUS "BUILD_TYPE=DEBUG")
    add_compile_definitions(VDEBUG)
endif()

if(WIN32)
    add_compile_definitions(VWINDOWS_PLATFORM)
    message(STATUS "PLATFORM=WINDOWS")
elseif(UNIX)
    add_compile_definitions(VUNIX_PLATFORM)
    message(STATUS "PLATFORM=UNIX")
elseif(APPLE)
    add_compile_definitions(VAPPLE_PLATFORM)
    message(STATUS "PLATFORM=APPLE")
endif()

add_subdirectory(vendor)
add_subdirectory(core)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME}
                        Core)
                    
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/core)