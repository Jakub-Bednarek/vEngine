#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "managers/LoggerManager.hpp"

#include <spdlog/spdlog.h>

#include <string>

namespace vEngine::logging
{
template <typename... Args>
void debug(const std::string& message, Args... args)
{
    #ifdef VDEBUG
        spdlog::get(core::LoggerManager::mainLoggerName)->debug(fmt::runtime(message), args...);

        if (core::LoggerManager::fileLoggerInitialized)
        {
            spdlog::get(core::LoggerManager::fileLoggerName)->debug(fmt::runtime(message), args...);
        }
    #endif // VDEBUG
}

template <typename... Args>
void info(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->info(fmt::runtime(message), args...);

    if (core::LoggerManager::fileLoggerInitialized)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->info(fmt::runtime(message), args...);
    }
}

template <typename... Args>
void warn(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->warn(fmt::runtime(message), args...);

    if (core::LoggerManager::fileLoggerInitialized)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->warn(fmt::runtime(message), args...);
    }
}

template <typename... Args>
void error(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->critical(fmt::runtime(message), args...);

    if (core::LoggerManager::fileLoggerInitialized)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->error(fmt::runtime(message), args...);
    }
}

template <typename... Args>
void critical(const std::string& message, Args... args)
{
    spdlog::get(core::LoggerManager::mainLoggerName)->error(fmt::runtime(message), args...);

    if (core::LoggerManager::fileLoggerInitialized)
    {
        spdlog::get(core::LoggerManager::fileLoggerName)->critical(fmt::runtime(message), args...);
    }
}
}

#endif // LOGGER_HPP