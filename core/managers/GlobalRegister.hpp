#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "IManager.hpp"
#include "LoggerManager.hpp"
#include "utils/Singleton.hpp"

namespace vEngine::core
{

class GlobalRegister : public IManager, public Singleton<GlobalRegister>
{
public:
    GlobalRegister() = default;
    ~GlobalRegister() = default;
    void startUp();
    void shutDown();
private:
    void registerManagersForStartUp();

    LoggerManager loggerManager;
};

}

#endif // GLOBAL_REGISTER_HPP