cmake_minimum_required(VERSION 3.14)

function(configure_gtest)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
endfunction()

if(${ENABLE_TESTING})
    message(STATUS "Testing enabled")
    configure_gtest()
endif()

function(add_ut_directory DIR)
    if(${ENABLE_TESTING})
        add_subdirectory(${DIR})
    endif()
endfunction()

function(add_test)
    set(options NO_OPTIONS)
    set(oneValueArgs TARGET)
    set(mutliValueArgs HEADERS SOURCES LIBRARIES)
    cmake_parse_arguments(TEST "${options}" "${oneValueArgs}" "${mutliValueArgs}" ${ARGN})

    add_executable(${TEST_TARGET}_test ${TEST_SOURCES})
    target_link_libraries(${TEST_TARGET}_test PRIVATE GTest::gtest_main GTest::gmock_main Core ${TEST_LIBRARIES})
    message(STATUS ${CMAKE_SOURCE_DIR})
    target_include_directories(${TEST_TARGET}_test PUBLIC ${CMAKE_SOURCE_DIR}/core)
    gtest_discover_tests(${TEST_TARGET}_test)
endfunction()