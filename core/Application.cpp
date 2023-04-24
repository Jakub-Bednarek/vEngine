#include "Application.hpp"
#include "logging/Logger.hpp"

#include <iostream>
#include <cassert>

namespace vEngine::core
{

Application::Application() : isInitialized(false) {}

Application::~Application()
{
}

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

bool Application::initialize()
{
    GlobalRegister::getInstance().startUp();

    window = WindowFactory::createWindow();

    if(!window)
    {
        return false;
    }

    window->initialize();
    timer.start();

    isInitialized = true;

    return true;
}

void Application::cleanUp()
{
    assert(isInitialized);

    window->cleanUp();
    window->destroy();

    GlobalRegister::getInstance().shutDown();
}

void Application::run()
{
    if(!isInitialized)
    {
        std::cout << "Initialize application before running!\n";
        return;
    }

    timer.setTimestamp();
    while(window->update())
    {
        auto deltaTime = timer.getElapsedTimeSinceTimestamp();
        logging::info("Time elapsed in ms: ");
        logging::info(std::to_string(deltaTime.asMilliseconds()));
        logging::info("Window updated!");
        timer.setTimestamp();
    }

    cleanUp();
}
}