#ifndef IMANAGER_HPP
#define IMANAGER_HPP

#include "Singleton.hpp"

#include <any>
#include <vector>
#include <memory>
#include <iostream>

namespace vEngine
{
namespace Core
{

template <typename T, typename... Managers>
class IManager : public Singleton<T>
{
public:
    IManager()
    {
        if constexpr(sizeof...(Managers) > 0)
        {
            createDependencies<Managers...>();
        }

        std::cout << "Creating " << typeid(T).name() << '\n';
    }
    virtual ~IManager()
    {
        std::cout << "Destructing " << typeid(T).name() << '\n';
    }

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
    template <typename Manager, typename... Args, std::enable_if_t<sizeof...(Args) != 0>>
    void createDependencies()
    {
        dependencies.push_back(Manager::create());
        createDependencies<Args...>();
    }

    template <typename Manager, typename... Args, std::enable_if_t<sizeof...(Args) == 0>>
    void createDependencies()
    {
        dependencies.push_back(Manager::create());
    }
private:
    std::vector<IManager<std::any>*> dependencies {};
};

}
}

#endif // IMANAGAER_HPP