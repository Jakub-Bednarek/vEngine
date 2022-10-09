#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

namespace vEngine
{
namespace Core
{

class Application
{
public:
    Application();
    ~Application();

    static std::shared_ptr<Application> createInstance();
    static std::shared_ptr<Application> getInstance();

    void initialize();
    void cleanUp();
    void run();
private:
    static std::shared_ptr<Application> instance;

    bool initialized;
    bool cleanedUp;
};

}
}

#endif // APPLICATION_HPP
