#ifndef ILOGGER_MANAGER_HPP
#define ILOGGER_MANAGER_HPP

#include "managers/IManager.hpp"

namespace vEngine::core
{

class ILoggerManager : public IManager
{
public:
    virtual ~ILoggerManager() = default;
};

}

#endif // ILOGGER_MANAGER_HPP