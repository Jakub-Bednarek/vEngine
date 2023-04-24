#pragma once

#include "window/WindowFactory.hpp"
#include "managers/GlobalRegister.hpp"
#include "utils/Timer.hpp"

#include <memory>

namespace vEngine::core
{

class Application
{
public:
    Application();
    ~Application();

    void run();
    void cleanUp();
    bool initialize();
    static std::shared_ptr<Application> createInstance();
private:
    void update() {}
    void draw() {}
private:
    inline static std::shared_ptr<Application> instance;

    bool isInitialized;
    std::shared_ptr<IWindow> window;
    GlobalRegister globalRegister;
    utils::Timer<> timer;
};

}
