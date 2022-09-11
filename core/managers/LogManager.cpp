#include "LogManager.hpp"

namespace vEngine
{
namespace Core
{

LogManager::LogManager(const std::string& logPath)
{
    std::cout << "Creating LogManager with path: " << logPath << "\n";
}

std::uint8_t LogManager::startUp()
{
    std::cout << "Hey LogManager is starting!\n";

    return 0;
}

std::uint8_t LogManager::shutDown() 
{
    std::cout << "LogManager is shutting down :(\n";

    return 0;
}

}
}