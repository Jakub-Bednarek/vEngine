#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../IWindow.hpp"

#include <X11/Xlib.h>
#include <GL/glx.h>
#include <cstdint>
#include <array>

namespace vEngine::core
{
class LinuxWindow : public IWindow
{
public:
    LinuxWindow();
    LinuxWindow(const std::uint16_t width, const std::uint16_t height);
    ~LinuxWindow() override;
    bool initialize() override;
    void clear() override;
    void cleanUp() override;
    void flush() override;
    void destroy() override;
    bool update() override;
private:
    std::uint16_t width;
    std::uint16_t height;

    bool isDestroyed = false;

    Display* display;
    Window rootWindow;
    Window window;
    XVisualInfo* visualInfo;
    GLXContext glContext;
    Colormap colorMap;
    std::array<GLint, 5> glAttributes { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XSetWindowAttributes setWindowAttributes;
    XWindowAttributes windowAtributes;
    XEvent lastEvent;

    static constexpr std::uint16_t defaultWidth = 1024;
    static constexpr std::uint16_t defaultHeight = 1024;
};
}

#endif // WINDOW_HPP