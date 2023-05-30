#include <gtest/gtest.h>

#include "managers/GlobalRegister.hpp"
#include "managers/WindowManager/WindowManager.hpp"
#include "managers/LoggerManager/LoggerManager.hpp"

using namespace testing;
using namespace vEngine::core;

TEST(GlobalRegister_tests, globalRegisterShouldCreateDefaultManagers)
{
    GlobalRegister sut;
    sut.registerAllManagers();

    ASSERT_TRUE(sut.getManagerPtr<LoggerManager>());
    ASSERT_TRUE(sut.getManagerPtr<WindowManager>());
}