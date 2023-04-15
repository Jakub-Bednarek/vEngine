#include <iostream>
#include "Application.hpp"

int main()
{
    auto app = vEngine::core::Application::createInstance();

    app->initialize();
    app->run();

    return 0;
}