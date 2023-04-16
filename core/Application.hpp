#pragma once

#include "window/WindowFactory.hpp"
#include "managers/GlobalRegister.hpp"

#include <memory>

namespace vEngine::core
{

class Application
{
public:
    Application();
    ~Application();

    static std::shared_ptr<Application> createInstance();
    bool initialize();
    void cleanUp();
    void run();
private:
    inline static std::shared_ptr<Application> instance;

    bool isInitialized;
    std::shared_ptr<IWindow> window;
    GlobalRegister globalRegister;
};

}
