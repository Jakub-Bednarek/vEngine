#include "WindowFactory.hpp"
#include "linux/WindowImpl.hpp"

#include <iostream>

namespace vEngine::core
{

std::shared_ptr<IWindow> WindowFactory::createWindow()
{
    std::cout << "Creating default window\n";
    return std::make_shared<LinuxWindow>();
}

std::shared_ptr<IWindow> WindowFactory::createWindow(const std::uint16_t width, const std::uint16_t height)
{
    std::cout << "Creating window with params\n";
    return std::make_shared<LinuxWindow >(width, height);
}

}