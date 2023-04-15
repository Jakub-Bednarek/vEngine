set(WINDOW_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/window)

set(CORE_HEADER_FILES
    Application.hpp
    ${WINDOW_INCLUDE}/IWindow.hpp
    ${WINDOW_INCLUDE}/WindowFactory.hpp
    ${WINDOW_INCLUDE}/linux/WindowImpl.hpp)
    
set(CORE_SOURCE_FILES
    Application.cpp
    ${WINDOW_INCLUDE}/WindowFactory.cpp
    ${WINDOW_INCLUDE}/linux/WindowImpl.cpp)

add_library(Core
    ${CORE_HEADER_FILES}
    ${CORE_SOURCE_FILES})

target_link_libraries(Core X11 GL GLU)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})