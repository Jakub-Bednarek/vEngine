#include "Application.hpp"
#include "logging/Logger.hpp"
#include "managers/WindowManager/WindowManager.hpp"

#include <iostream>
#include <cassert>

namespace vEngine::core
{
std::shared_ptr<Application> Application::createInstance()
{
    if(Application::instance)
    {
        std::cout << "Instance of Application already created!\n";
        return Application::instance;
    }

    Application::instance = std::make_shared<Application>();
    std::cout << "Successfully created Application instance.\nCreating static managers...\n";

    // GlobalRegister::createStaticManagers();
    std::cout << "Static managers created\n";

    return Application::instance;
}

ErrorCode Application::initialize()
{
    globalRegister.registerAllManagers();
    globalRegister.startUp();
    timer.start();

    windowInstance = globalRegister.getManagerPtr<WindowManager>()->getWindowInstance();

    isInitialized = true;

    return ErrorCode::NONE;
}

void Application::cleanUp()
{
    assert(isInitialized);

    globalRegister.shutDown();
}

void Application::handleShutDown()
{
    logging::info("Shutting down application.");

    cleanUp();
}

ErrorCode Application::run()
{
    if(!isInitialized)
    {
        std::cout << "Initialize application before running!\n";
        return ErrorCode::APPLICATION_UNINITIALIZED;
    }

    isRunning = true;
    timer.setTimestamp();
    while(isRunning)
    {
        const auto deltaTime = timer.getElapsedTimeSinceTimestamp();
        timer.setTimestamp();

        const auto shouldTerminate = update(deltaTime);

        if(static_cast<bool>(shouldTerminate))
        {
            isRunning = false;
            handleShutDown();
        }
    }

    return ErrorCode::NONE;
}

ExitCode Application::update(const utils::TimeStamp& deltaTime)
{
    logging::info("Time elapsed: {0:.2f}ms", deltaTime.asMilliseconds());

    if(!windowInstance->update())
    {
        return ExitCode::WINDOW_CLOSED;
    }

    return ExitCode::NONE;
}

void Application::draw()
{
}
}