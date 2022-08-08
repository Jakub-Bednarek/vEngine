#include "Application.hpp"

#include <iostream>

namespace vEngine
{
namespace Core
{
std::shared_ptr<Application> Application::instance;

std::shared_ptr<Application> Application::createInstance()
{
    if(Application::instance)
    {
        std::cout << "Instance of Application already created!\n";
        return Application::instance;
    }

    Application::instance = std::make_shared<Application>();
    std::cout << "Successfully created Application instance.\n";

    return Application::instance;
}

void Application::run()
{
    std::cout << "Running!\n";
}
}
}