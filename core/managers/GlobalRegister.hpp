#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "IManager.hpp"
#include "utils/Singleton.hpp"

#include "LoggerManager.hpp"
#include "WindowManager.hpp"

namespace vEngine::core
{

class LoggerManager;
class WindowManager;

class GlobalRegister : public IManager, public Singleton<GlobalRegister>
{
public:
    GlobalRegister() = default;
    ~GlobalRegister() = default;
    bool startUp();
    void shutDown();
private:
    LoggerManager loggerManager;
    WindowManager windowManager;
};

}

#endif // GLOBAL_REGISTER_HPP