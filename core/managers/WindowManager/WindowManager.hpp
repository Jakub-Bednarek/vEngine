#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include "IWindowManager.hpp"

namespace vEngine::core
{

class IWindow;

class WindowManager : public IWindowManager
{
public:
    bool startUp() override;
    void shutDown() override;

    std::shared_ptr<IWindow> getWindowInstance() const override;
private:
    std::shared_ptr<IWindow> windowInstance = nullptr;
};

}

#endif // WINDOW_MANAGER_HPP