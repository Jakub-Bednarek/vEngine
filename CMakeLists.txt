cmake_minimum_required(VERSION 3.21s)
project(vEngine)

SET(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME}
                        Core
                    )
                    
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/core)