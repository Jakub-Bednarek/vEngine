#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include "IManager.hpp"

namespace vEngine
{
namespace Core
{

class LogManager : public IManager
{
public:
    LogManager();
    ~LogManager() = default;

    std::uint8_t startUp() override;
    std::uint8_t shutDown() override;
};

}
}


#endif // LOG_MANAGER_HPP