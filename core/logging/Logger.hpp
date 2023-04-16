#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "managers/LoggerManager.hpp"

#include <spdlog/spdlog.h>

#include <string>

constexpr auto isDebug = true;

namespace vEngine::logging
{
template <typename... Args>
void debug(const std::string& message, Args... args)
{
    if constexpr(isDebug)
    {
        spdlog::get(core::LoggerManager::mainLoggerName)->debug(message, args...);

        if constexpr(core::LoggerManager::fileLoggingEnabled)
        {
            spdlog::get(core::LoggerManager::fileLoggerName)->debug(message, args...);
        }
    }
}

template <typename... Args>
void info(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->info(message, args...);

    if constexpr(core::LoggerManager::fileLoggingEnabled)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->info(message, args...);
    }
}

template <typename... Args>
void warn(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->warn(message, args...);

    if constexpr(core::LoggerManager::fileLoggingEnabled)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->warn(message, args...);
    }
}

template <typename... Args>
void error(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->critical(message, args...);

    if constexpr(core::LoggerManager::fileLoggingEnabled)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->error(message, args...);
    }
}

template <typename... Args>
void critical(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->error(message, args...);

    if constexpr(core::LoggerManager::fileLoggingEnabled)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->critical(message, args...);
    }
}
}

#endif // LOGGER_HPP