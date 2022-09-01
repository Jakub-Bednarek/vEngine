#include "LogManager.hpp"

namespace vEngine
{
namespace Core
{

LogManager::LogManager()
{
    std::cout << "Creating LogManager!\n";
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