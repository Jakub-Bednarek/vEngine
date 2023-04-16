#include "GlobalRegister.hpp"
#include "LoggerManager.hpp"

namespace vEngine::core
{

void GlobalRegister::startUp()
{
    loggerManager.startUp();
}

void GlobalRegister::shutDown()
{
    loggerManager.shutDown();
}
}