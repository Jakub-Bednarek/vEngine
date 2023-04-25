#include "GlobalRegister.hpp"
#include "logging/Logger.hpp"

namespace vEngine::core
{

bool GlobalRegister::startUp()
{
    std::cout << "Initializing all managers.\n";

    assert(LoggerManager::getInstancePtr());
    assert(WindowManager::getInstancePtr());

    loggerManager.startUp();
    windowManager.startUp();


    logging::info("All managers successfully initialized.");

    return true;
}

void GlobalRegister::shutDown()
{
    windowManager.shutDown();
    loggerManager.shutDown();
}
}