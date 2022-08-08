#include <iostream>
#include "Application.hpp"

int main()
{
    auto app = vEngine::Core::Application::createInstance();

    app->run();

    return 0;
}