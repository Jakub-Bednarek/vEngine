#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include "IManager.hpp"

#include <string>

namespace vEngine
{
namespace Core
{

class LogManager : public IManager<LogManager>
{
public:
    LogManager();
    ~LogManager() override = default;

    std::uint8_t startUp() override;
    std::uint8_t shutDown() override;
};

}
}


#endif // LOG_MANAGER_HPP