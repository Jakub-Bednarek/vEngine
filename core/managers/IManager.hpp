#ifndef IMANAGER_HPP
#define IMANAGER_HPP

namespace vEngine::core
{

class IManager
{
public:
    virtual ~IManager() = default;
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
};

}

#endif // IMANAGER_HPP