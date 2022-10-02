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

    template <typename T, typename... _Args>
    void registerManager(_Args&&... args)
    {
        registeredManagers.insert(std::make_shared<T>(std::forward<_Args...>(args...)));
    }
private:
    std::set<std::shared_ptr<IManager>> registeredManagers;
};

}
}

#define REGISTER_MANAGER(MANAGER, ...) vEngine::Core::GlobalRegister::registerManager<MANAGER>(std::forward(__VA_ARGS__));

#endif // GLOBAL_REGISTER_HPP