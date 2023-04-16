#include "WindowFactory.hpp"

#ifdef __linux__
#include "linux/WindowImpl.hpp"
#endif

#include <iostream>

namespace vEngine::core
{

std::shared_ptr<IWindow> WindowFactory::createWindow()
{
    return std::make_shared<LinuxWindow>();
}

std::shared_ptr<IWindow> WindowFactory::createWindow(const std::uint16_t width, const std::uint16_t height)
{
    return std::make_shared<LinuxWindow >(width, height);
}

}