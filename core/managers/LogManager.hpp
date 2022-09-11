#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include "IManager.hpp"
#include "GlobalRegister.hpp"

#include <string>

namespace vEngine
{
namespace Core
{

class LogManager : public IManager
{
public:
    LogManager(const std::string& logPath);
    ~LogManager() = default;

    std::uint8_t startUp() override;
    std::uint8_t shutDown() override;
};

}
}

vEngine::Core::GlobalRegister::registerManager<vEngine::Core::LogManager>("123");


#endif // LOG_MANAGER_HPP