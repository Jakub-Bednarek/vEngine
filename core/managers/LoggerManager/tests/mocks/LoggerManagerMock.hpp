#ifndef LOGGER_MANAGER_MOCK_HPP
#define LOGGER_MANAGER_MOCK_HPP

#include "managers/LoggerManager/ILoggerManager.hpp"

#include <gmock/gmock.h>

namespace vEngine::core
{
class LoggerManagerMock : public ILoggerManager
{
public:
    LoggerManagerMock();
    virtual ~LoggerManagerMock();
    MOCK_METHOD(bool, startUp, (), (override));
    MOCK_METHOD(void, shutDown, (), (override));
};
}

#endif // LOGGER_MANAGER_MOCK_HPP