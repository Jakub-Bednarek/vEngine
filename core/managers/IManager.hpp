#ifndef IMANAGER_HPP
#define IMANAGER_HPP

#include <cstdint>

namespace vEngine::core
{

using Priority = std::uint16_t;

class IManager
{
public:
    IManager(const Priority priority): priority(priority) {}
    virtual ~IManager() = default;
    virtual bool startUp() = 0;
    virtual void shutDown() = 0;

    Priority getPriority() const noexcept { return priority; }
private:
    Priority priority;
};

}

#endif // IMANAGER_HPP