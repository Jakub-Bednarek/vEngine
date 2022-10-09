#ifndef SINGLETONE_HPP
#define SINGLETONE_HPP

#include <memory>
#include <mutex>
#include <cassert>

namespace vEngine
{
namespace Core
{

template <typename T>
class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete; 

    static T getInstance()
    {
        assert(instance);

        return instance.get();
    }

    static T* create()
    {
        std::lock_guard<std::mutex> lockGuard(mutex);

        if(!instance)
        {
            instance = std::make_unique<T>();
        }

        return instance.get();
    }
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
private:
    inline static std::shared_ptr<T> instance = nullptr;
    inline static std::mutex mutex;
};

}
}

#endif // SINGLETONE_HPP