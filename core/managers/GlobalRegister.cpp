#include "GlobalRegister.hpp"
#include "LoggerManager.hpp"
#include "logging/Logger.hpp"

namespace vEngine::core
{

bool GlobalRegister::startUp()
{
    std::cout << "Initializing all managers.\n";

    loggerManager.startUp();

    logging::info("All managers successfully initialized.");

    return true;
}

void GlobalRegister::shutDown()
{
    loggerManager.shutDown();
}
}