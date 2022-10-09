#include "Application.hpp"

#include "managers/LogManager.hpp"

#include <iostream>

namespace vEngine
{
namespace Core
{
std::shared_ptr<Application> Application::instance;

Application::Application() : initialized(false), cleanedUp(false) {}
Application::~Application()
{
    if(!cleanedUp)
    {
        cleanUp();
    }
}

std::shared_ptr<Application> Application::createInstance()
{
    if(Application::instance)
    {
        std::cout << "Instance of Application already exists, returning instance!\n";
        return Application::instance;
    }

    Application::instance = std::make_shared<Application>();
    std::cout << "Successfully created Application instance.\n";

    return Application::instance;
}

std::shared_ptr<Application> Application::getInstance()
{
    return Application::instance;
}

void Application::initialize()
{
    std::cout << "Initializing application.\n";

    initialized = true;
}

void Application::cleanUp()
{
    std::cout << "Cleaning up to shut down application\n";
}

void Application::run()
{
    if(!initialized)
    {
        std::cout << "Trying to run unitialized application, returning!\n";
        return;
    }

    std::cout << "Running!\n";
}
}
}