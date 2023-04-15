#ifndef WINDOW_FACTORY_HPP
#define WINDOW_FACTORY_HPP

#include "IWindow.hpp"

#include <memory>
#include <cstdint>

namespace vEngine::core
{

class WindowFactory
{
public:
    static std::shared_ptr<IWindow> createWindow();
    static std::shared_ptr<IWindow> createWindow(const std::uint16_t width, const std::uint16_t height);
};

}

#endif // WINDOW_FACTORY_HPP