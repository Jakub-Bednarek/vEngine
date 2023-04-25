#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include "IManager.hpp"
#include "utils/Singleton.hpp"

#include <memory>

namespace vEngine::core
{

class IWindow;

class WindowManager : public IManager, public Singleton<WindowManager>
{
public:
    bool startUp() override;
    void shutDown() override;

    std::shared_ptr<IWindow> getWindowInstance() const;
private:
    std::shared_ptr<IWindow> windowInstance = nullptr;
};

}

#endif // WINDOW_MANAGER_HPP