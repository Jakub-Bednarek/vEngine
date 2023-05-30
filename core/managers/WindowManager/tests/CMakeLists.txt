add_library(WindowManagerMock mocks/WindowManagerMock.cpp)
target_include_directories(WindowManagerMock PUBLIC ${CMAKE_SOURCE_DIR}/core)
target_link_libraries(WindowManagerMock PUBLIC GTest::gmock_main)