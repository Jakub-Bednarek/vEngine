SET(CORE_HEADER_FILES
    Application.hpp)
    
SET(CORE_SOURCE_FILES
    Application.cpp
    managers/LogManager.cpp)

add_library(Core
    ${CORE_HEADER_FILES}
    ${CORE_SOURCE_FILES})

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})