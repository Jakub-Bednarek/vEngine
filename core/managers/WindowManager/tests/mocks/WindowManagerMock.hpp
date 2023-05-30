
#ifndef WINDOW_MANAGER_MOCK_HPP
#define WINDOW_MANAGER_MOCK_HPP

#include "managers/WindowManager/IWindowManager.hpp"

#include <gmock/gmock.h>

namespace vEngine::core
{
class WindowManagerMock : public IWindowManager
{
public:
    WindowManagerMock();
    virtual ~WindowManagerMock();
    MOCK_METHOD(bool, startUp, (), (override));
    MOCK_METHOD(void, shutDown, (), (override));
    MOCK_METHOD(std::shared_ptr<IWindow>, getWindowInstance, (), (const, override));
};
}

#endif // WINDOW_MANAGER_MOCK_HPP