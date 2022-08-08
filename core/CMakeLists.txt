

SET(CORE_HEADER_FILES
    Application.hpp)
    
SET(CORE_SOURCE_FILES
    Application.cpp)

add_library(Core
    ${CORE_HEADER_FILES}
    ${CORE_SOURCE_FILES})