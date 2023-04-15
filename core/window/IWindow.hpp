#ifndef IWINDOW_HPP
#define IWINDOW_HPP

namespace vEngine::core
{

class IWindow
{
public:
    virtual ~IWindow() = default;
    virtual bool initialize() = 0;
    virtual void clear() = 0;
    virtual void cleanUp() = 0;
    virtual void flush() = 0;
    virtual void destroy() = 0;
    virtual bool update() = 0;
};

}

#endif // IWINDOW_HPP