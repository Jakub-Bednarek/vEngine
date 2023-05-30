add_library(LoggerManagerMock mocks/LoggerManagerMock.cpp)
target_include_directories(LoggerManagerMock PUBLIC ${CMAKE_SOURCE_DIR}/core)
target_link_libraries(LoggerManagerMock PUBLIC GTest::gmock_main)