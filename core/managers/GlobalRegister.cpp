#include "GlobalRegister.hpp"
#include "logging/Logger.hpp"

#include <iostream>

namespace vEngine::core
{
void GlobalRegister::createStaticManagers(std::shared_ptr<ILoggerManager> loggerManagerInstance,
                                          std::shared_ptr<IWindowManager> windowManagerInstance)
{
    loggerManager = std::move(loggerManagerInstance);
    windowManager = std::move(windowManagerInstance);
}

bool GlobalRegister::startUp()
{
    std::cout << "Initializing all managers.\n";

    loggerManager->startUp();
    windowManager->startUp();

    logging::info("All managers successfully initialized.");

    return true;
}

void GlobalRegister::shutDown()
{
    windowManager->shutDown();
    loggerManager->shutDown();
}
}