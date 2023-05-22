#include "WindowManager.hpp"

#include "window/linux/WindowImpl.hpp"
#include "window/WindowFactory.hpp"

#include <cassert>

namespace vEngine::core
{

bool WindowManager::startUp()
{
    assert(!windowInstance);
    
    windowInstance = WindowFactory::createWindow(1280, 720);
    windowInstance->initialize();

    assert(windowInstance);

    return true;
}

void WindowManager::shutDown()
{
    assert(windowInstance);

    windowInstance->flush();
    windowInstance->clear();
    windowInstance->cleanUp();
    windowInstance->destroy();
    windowInstance = nullptr;

    assert(!windowInstance);
}

std::shared_ptr<IWindow> WindowManager::getWindowInstance() const
{
    return windowInstance;
}

}