#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "IManager.hpp"
#include "LogManager.hpp"

#include <variant>
#include <vector>

namespace vEngine
{
namespace Core
{

class GlobalRegister
{
public:
    using SupportedManagers = std::variant<LogManager*>;

    GlobalRegister() = default;
    ~GlobalRegister() = default;

    void startupManagers()
    {
        std::cout << "Starting up managers\n";

        for(auto& manager : registeredManagers)
        {
            std::visit([](auto&& arg) { arg->startUpDependecies(); arg->startUp(); }, manager);
        }
    }

    void shutDownManagers()
    {
        std::cout << "Shutting down managers\n";

        for(auto& manager : registeredManagers)
        {
            std::visit([](auto&& arg) { arg->shutDownDependencies(); arg->shutDown(); }, manager);
        }
    }

    void registerManagers()
    {
        std::cout << "Registering managers\n";

        auto manager = LogManager::create();
        registeredManagers.push_back(SupportedManagers(LogManager::create()));
    }

private:
    std::vector<SupportedManagers> registeredManagers {};
};

}
}

#endif // GLOBAL_REGISTER_HPP