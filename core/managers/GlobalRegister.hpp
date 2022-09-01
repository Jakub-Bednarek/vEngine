#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "IManager.hpp"

namespace vEngine
{
namespace Core
{

class GlobalRegister
{
public:
    GlobalRegister() = default;
    ~GlobalRegister() = default;

    std::uint8_t startManagers()
    {
        std::cout << "GlobalRegister is starting all managers\n";

        auto returnCode { 0 };
        for(auto& manager : registeredManagers)
        {
            returnCode = manager->startUpDependecies();

            if(!returnCode)
            {
                returnCode = manager->startUp();
            }
        }

        return returnCode;
    }

    std::uint8_t shutDownManagers()
    {
        std::cout << "GlobalRegister is shutting down all managers\n";

        auto returnCode { 0 };
        for(auto& manager : registeredManagers)
        {
            returnCode = manager->shutDownDependencies();

            if(!returnCode)
            {
                returnCode = manager->shutDown();
            }
        }

        return returnCode;
    }

    template <typename T>
    void registerManager()
    {
        registeredManagers.insert(std::make_shared<T>());
    }
private:
    std::set<std::shared_ptr<IManager>> registeredManagers;
};

}
}

#endif // GLOBAL_REGISTER_HPP