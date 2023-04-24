#pragma once

#include "window/WindowFactory.hpp"
#include "managers/GlobalRegister.hpp"
#include "utils/Timer.hpp"

#include <memory>

namespace vEngine::core
{

enum class ExitCode : std::uint8_t
{
    NONE = 0x0,
    WINDOW_CLOSED = 0x1
};

enum class ErrorCode : std::uint8_t
{
    NONE = 0x0,
    APPLICATION_UNINITIALIZED = 0x1,
    WINDOW_CREATION_FAILURE = 0x2
};

class Application
{
public:
    Application() = default;
    ~Application() = default;

    static std::shared_ptr<Application> createInstance();

    ErrorCode run();
    void cleanUp();
    void handleShutDown();
    ErrorCode initialize();
private:
    ExitCode update(const utils::TimeStamp& deltaTime);
    void draw();
private:
    inline static std::shared_ptr<Application> instance;

    bool isInitialized = false;
    bool isRunning = false;
    std::shared_ptr<IWindow> window;
    GlobalRegister globalRegister;
    utils::Timer<> timer;
};

}
