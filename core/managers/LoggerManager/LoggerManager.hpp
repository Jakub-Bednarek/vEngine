#ifndef LOGGER_MANAGER_HPP
#define LOGGER_MANAGER_HPP

#ifndef SPDLOG_HEADER_ONLY
    #define SPDLOG_HEADER_ONLY
#endif

#include "ILoggerManager.hpp"

namespace vEngine::core
{

class LoggerManager : public ILoggerManager
{
public:
    LoggerManager() = default;
    ~LoggerManager() = default;
    bool startUp() override;
    void shutDown() override;

    static constexpr auto mainLoggerName = "console";
    static constexpr auto fileLoggerName = "fileLogger";
    static constexpr auto defaultLogDir = "logs/basic-log.txt";
    static constexpr auto fileLoggerEnabled = true;

    inline static bool fileLoggerInitialized = false;
private:
    void createLogger();
};

}

#endif // LOGGER_MANAGER_HPP