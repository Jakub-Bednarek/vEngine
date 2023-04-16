#ifndef LOGGER_MANAGER_HPP
#define LOGGER_MANAGER_HPP

#include "IManager.hpp"
#include "utils/Singleton.hpp"

namespace vEngine::core
{

class LoggerManager : public IManager, public Singleton<LoggerManager>
{
public:
    void startUp() override;
    void shutDown() override;
};

}

#endif // LOGGER_MANAGER_HPP