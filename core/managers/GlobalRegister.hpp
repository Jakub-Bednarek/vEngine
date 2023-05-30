#ifndef GLOBAL_REGISTER_HPP
#define GLOBAL_REGISTER_HPP

#include "IManager.hpp"
#include "logging/Logger.hpp"

#include <map>
#include <memory>
#include <map>
#include <algorithm>
#include <iostream>

namespace vEngine::core
{

class GlobalRegister 
{
    struct ManagerKey
    {
        Priority priority;
        const char* name;
    };

    struct ManagerKeyComparator
    {
        bool operator()(const ManagerKey& lhs, const ManagerKey& rhs) const
        {
            return lhs.priority > rhs.priority;
        }
    };

    using ManagersMap = std::map<ManagerKey, std::shared_ptr<IManager>, ManagerKeyComparator>;
public:
    ~GlobalRegister() = default;
    bool startUp();
    void shutDown();
    void registerAllManagers();

    template <typename T>
    bool registerManager()
    {
        auto managerName = typeid(T).name();
        if(find(managerName) != registeredManagers.end())
        {
            return false;
        }

        auto managerToRegister = std::make_shared<T>();
        registeredManagers.emplace(ManagerKey { .priority = managerToRegister->getPriority(), .name = std::move(managerName) }, std::move(managerToRegister));
        return true;
    }

    template <typename T>
    T* getManagerPtr()
    {
        const auto managerName = typeid(T).name();
        auto foundManager = find(managerName);
        if(foundManager == registeredManagers.end())
        {
            logging::error("Failed to find {0} manager, used before register.", managerName);
            assert(false);
        }

        return dynamic_cast<T*>(foundManager->second.get());
    }

    template <typename T>
    T& getManager()
    {
        return *getManagerPtr<T>();
    }
private:
    ManagersMap::iterator find(const char* name)
    {
        return std::find_if(registeredManagers.begin(), registeredManagers.end(), [&name](const auto& managerEntry) { return strcmp(name, managerEntry.first.name) == 0; });
    }

    ManagersMap registeredManagers;
};

}

#endif // GLOBAL_REGISTER_HPP