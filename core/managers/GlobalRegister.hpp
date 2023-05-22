#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "LoggerManager/LoggerManager.hpp"
#include "WindowManager/WindowManager.hpp"

#include <map>
#include <memory>
#include <cassert>

namespace vEngine::core
{

class GlobalRegister 
{
public:
    ~GlobalRegister() = default;
    bool startUp();
    void shutDown();

    static void createStaticManagers(std::shared_ptr<ILoggerManager> = std::make_shared<LoggerManager>(),
                                     std::shared_ptr<IWindowManager> = std::make_shared<WindowManager>());

    static std::shared_ptr<ILoggerManager> getLoggerManager() { assert(loggerManager); return loggerManager; }
    static std::shared_ptr<IWindowManager> getWindowManager()  { assert(windowManager); return windowManager; }
private:
    inline static std::shared_ptr<ILoggerManager> loggerManager = nullptr;
    inline static std::shared_ptr<IWindowManager> windowManager = nullptr;
};

}

#endif // GLOBAL_REGISTER_HPP