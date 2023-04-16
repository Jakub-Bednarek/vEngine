#include "LoggerManager.hpp"
#include "logging/Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <iostream>

namespace vEngine::core
{

bool LoggerManager::startUp()
{
    auto mainLogger = spdlog::stdout_color_mt(mainLoggerName);
    mainLogger->set_level(spdlog::level::debug);

    logging::info("Main logger initialized successfuly, logger name: ");

    if constexpr (fileLoggingEnabled)
    {
        try
        {
            auto fileLogger = spdlog::basic_logger_mt(fileLoggerName, defaultLogDir);
            fileLogger->set_level(spdlog::level::debug);

            logging::info("File logger initialized successfully, logger name: , log file: ");
        }
        catch(const spdlog::spdlog_ex &ex)
        {
            std::cout << "Failed to create file logger: " << ex.what() << '\n';
            return false;
        }
    }
    else
    {
        logging::info("File logging disabled, file logger not initialized.");
    }

    
    return true;
}

void LoggerManager::shutDown()
{
    logging::info("Shutting down LoggerManager");

    spdlog::get(mainLoggerName)->flush();

    if constexpr (fileLoggingEnabled)
    {
        spdlog::get(fileLoggerName)->flush();
    }
}

}