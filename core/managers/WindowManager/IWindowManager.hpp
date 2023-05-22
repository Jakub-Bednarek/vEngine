#ifndef IWINDOW_MANAGER_HPP
#define IWINDOW_MANAGER_HPP

#include "managers/IManager.hpp"
#include "window/IWindow.hpp"

#include <memory>

namespace vEngine::core
{

class IWindowManager : public IManager
{
public:
    virtual ~IWindowManager() = default;
    virtual std::shared_ptr<IWindow> getWindowInstance() const = 0;
};

}

#endif // IWINDOW_MANAGER_HPP