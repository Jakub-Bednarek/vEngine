#ifndef IMANAGER_HPP
#define IMANAGER_HPP

#include <cstdint>
#include <set>
#include <iostream>
#include <typeinfo>
#include <memory>

namespace vEngine
{
namespace Core
{

class IManager
{
public:
    IManager() = default;
    virtual ~IManager() = default;

    virtual std::uint8_t startUp() = 0;
    virtual std::uint8_t shutDown() = 0;

    virtual std::uint8_t startUpDependecies()
    {
        const auto managerName = typeid(*this).name();
        std::cout << "Starting " << managerName << '\n';

        for(auto& manager : dependencies)
        {
            if(const auto returnCode = manager->startUpDependecies(); returnCode)
            {
                std::cout << "Failed to start " << managerName << " with return code: " << returnCode << '\n';
                return returnCode;
            }
        }

        std::cout << "Successfuly started " << managerName << '\n';
        return 0;
    }

    virtual std::uint8_t shutDownDependencies()
    {
        const auto managerName = typeid(*this).name();
        std::cout << "Shutting down " << managerName << '\n';

        for(auto& manager : dependencies)
        {
            if(const auto returnCode = manager->shutDownDependencies(); returnCode)
            {
                std::cout << "Failed to shut down " << managerName << " with return code: " << returnCode << '\n';
                return returnCode;
            }
        }

        std::cout << "Successfuly shut down " << managerName << '\n';
        return 0;
    }
protected:
    std::set<std::shared_ptr<IManager>> dependencies {};
    bool initialized { false };
};

}
}

#endif // IMANAGAER_HPP