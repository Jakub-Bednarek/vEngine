#ifndef IWINDOW_MANAGER_HPP
#define IWINDOW_MANAGER_HPP

#include "managers/IManager.hpp"
#include "window/IWindow.hpp"

#include <memory>

namespace vEngine::core
{

namespace
{
constexpr Priority windowManagerPriority = 9;
}

class IWindowManager : public IManager
{
public:
    IWindowManager(): IManager(windowManagerPriority) {}
    virtual ~IWindowManager() = default;
    virtual std::shared_ptr<IWindow> getWindowInstance() const = 0;
};

}

#endif // IWINDOW_MANAGER_HPP