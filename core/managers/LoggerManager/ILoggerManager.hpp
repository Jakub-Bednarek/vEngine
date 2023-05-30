#ifndef ILOGGER_MANAGER_HPP
#define ILOGGER_MANAGER_HPP

#include "managers/IManager.hpp"

namespace vEngine::core
{

namespace
{
constexpr Priority loggerManagerPriority = 10;
}

class ILoggerManager : public IManager
{
public:
    ILoggerManager(): IManager(loggerManagerPriority) {}
    virtual ~ILoggerManager() = default;
};

}

#endif // ILOGGER_MANAGER_HPP