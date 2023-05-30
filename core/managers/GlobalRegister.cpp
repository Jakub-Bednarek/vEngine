#include "GlobalRegister.hpp"
#include "logging/Logger.hpp"
#include "LoggerManager/LoggerManager.hpp"
#include "WindowManager/WindowManager.hpp"

#include <iostream>
#include <cassert>

namespace vEngine::core
{
void GlobalRegister::registerAllManagers()
{
    assert(registerManager<LoggerManager>());
    assert(registerManager<WindowManager>());
}

bool GlobalRegister::startUp()
{
    std::cout << "Initializing all managers.\n";
    
    for(auto& manager : registeredManagers)
    {
        manager.second->startUp();
    }

    logging::info("All managers successfully initialized.");

    return true;
}

void GlobalRegister::shutDown()
{
    logging::debug("Starting shut down of managers.");

    for(auto managerIt = registeredManagers.rbegin(); managerIt != registeredManagers.rend(); managerIt++)
    {
        managerIt->second->shutDown();
    }

    logging::info("All managers shut down successfuly.");
}
}