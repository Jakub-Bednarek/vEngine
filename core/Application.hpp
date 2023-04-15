#pragma once

#include "window/WindowFactory.hpp"

#include <memory>

namespace vEngine::core
{

class Application
{
public:
    Application();
    ~Application() = default;

    static std::shared_ptr<Application> createInstance();
    bool initialize();
    void run();
private:
    inline static std::shared_ptr<Application> instance;

    bool isInitialized;
    std::shared_ptr<IWindow> window;
};

}
