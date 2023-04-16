#include "LoggerManager.hpp"

#include <iostream>

namespace vEngine::core
{

void LoggerManager::startUp()
{
    std::cout << "Starting up LoggerManager\n";
}

void LoggerManager::shutDown()
{
    std::cout << "Shutting down LoggerManager\n";
}

}