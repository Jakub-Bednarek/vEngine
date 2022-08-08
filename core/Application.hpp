#pragma once

#include <memory>

namespace vEngine
{
namespace Core
{

class Application
{
public:
    Application() = default;
    ~Application() = default;

    static std::shared_ptr<Application> createInstance();
    void run();
private:
    static std::shared_ptr<Application> instance;
};

}
}
