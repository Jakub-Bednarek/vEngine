set(WINDOW_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/window)
set(UTILS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/utils)
set(MANAGERS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/managers)

set(CORE_HEADER_FILES
    Application.hpp
    ${WINDOW_INCLUDE}/IWindow.hpp
    ${WINDOW_INCLUDE}/WindowFactory.hpp
    ${WINDOW_INCLUDE}/linux/WindowImpl.hpp
    ${MANAGERS_INCLUDE}/LoggerManager/LoggerManager.hpp
    ${MANAGERS_INCLUDE}/LoggerManager/ILoggerManager.hpp
    ${MANAGERS_INCLUDE}/WindowManager/WindowManager.hpp
    ${MANAGERS_INCLUDE}/WindowManager/IWindowManager.hpp
    ${MANAGERS_INCLUDE}/GlobalRegister.hpp)
    
set(CORE_SOURCE_FILES
    Application.cpp
    ${WINDOW_INCLUDE}/WindowFactory.cpp
    ${WINDOW_INCLUDE}/linux/WindowImpl.cpp
    ${MANAGERS_INCLUDE}/LoggerManager/LoggerManager.cpp
    ${MANAGERS_INCLUDE}/WindowManager/WindowManager.cpp
    ${MANAGERS_INCLUDE}/GlobalRegister.cpp
    )

add_library(Core
    ${CORE_HEADER_FILES}
    ${CORE_SOURCE_FILES})

target_link_libraries(Core spdlog X11 GL GLU)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})