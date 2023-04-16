#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <cassert>
#include <mutex>
#include <iostream>

namespace vEngine::core
{

template <typename T>
class Singleton
{
public:
    Singleton()
    {
        assert(!instance);
        instance = static_cast<T*>(this);
    }

    virtual ~Singleton()
    {
        assert(instance);
        instance = nullptr;       
    }

    static T& getInstance()
    {
        return *instance;
    }

    static T* getInstancePtr()
    {
        return instance;
    }
private:
    Singleton(const Singleton&) = default;
    Singleton& operator=(const Singleton&) = default;

    std::once_flag createInstanceFlag;
    std::once_flag deleteInstanceFlag;
    static inline T* instance;
};

}

#endif // SINGLETON_HPP