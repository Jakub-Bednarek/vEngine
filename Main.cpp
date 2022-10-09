#include <iostream>
#include "Application.hpp"
#include "managers/GlobalRegister.hpp"

int main()
{
    auto globalRegister = std::make_unique<vEngine::Core::GlobalRegister>();

    globalRegister->registerManagers();
    globalRegister->startupManagers();

    auto app = vEngine::Core::Application::createInstance();

    app->initialize();
    app->run();
    app->cleanUp();

    globalRegister->shutDownManagers();

    return 0;
}