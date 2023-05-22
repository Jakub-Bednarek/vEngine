#include "WindowImpl.hpp"
#include "logging/Logger.hpp"
#include "renderer/Renderer.hpp"

#include <iostream>
#include <stdio.h>
#include <GL/glu.h>

namespace vEngine::core
{

LinuxWindow::LinuxWindow() : width(defaultWidth), height(defaultWidth) {}

LinuxWindow::LinuxWindow(const std::uint16_t width, const std::uint16_t height) : width(width), height(height) {}

LinuxWindow::~LinuxWindow()
{
    if(!isDestroyed)
    {
        cleanUp();
        destroy();
    }
}

bool LinuxWindow::initialize()
{
    logging::info("Initializing LinuxWindow");

    display = XOpenDisplay(nullptr);

    if(!display)
    {
        logging::error("Failed to create display, exiting");
        return false;
    }

    rootWindow = DefaultRootWindow(display);

    if(!rootWindow)
    {
        logging::error("Failed to create root window, exiting");
        return false;
    }

    visualInfo = glXChooseVisual(display, 0, glAttributes.data());

    if(!visualInfo)
    {
        logging::error("Failed to set visualInfo for choosen display");
        return false;
    }
    
    logging::info("Selected visualInfo with id: {}", visualInfo->visual->visualid);
    
    colorMap = XCreateColormap(display, rootWindow, visualInfo->visual, AllocNone);
    setWindowAttributes.colormap = colorMap;
    setWindowAttributes.event_mask = ExposureMask | KeyPressMask;
    window = XCreateWindow(display, rootWindow, 0, 0, width, height, 0, visualInfo->depth, InputOutput, visualInfo->visual, CWColormap | CWEventMask, &setWindowAttributes);
    
    XMapWindow(display, window);
    XStoreName(display, window, "vEngine");

    glContext = glXCreateContext(display, visualInfo, nullptr, GL_TRUE);
    glXMakeCurrent(display, window, glContext);

    logging::info("LinuxWindow created successfully");

    return true;
}

void LinuxWindow::clear()
{
    logging::debug("Clearing LinuxWindow");
}

void LinuxWindow::cleanUp()
{
    logging::debug("Cleaning up LinuxWindow");
}

void LinuxWindow::flush()
{
    logging::debug("Flushing LinuxWindow");
}

void LinuxWindow::destroy()
{
    if(isDestroyed)
    {
        logging::warn("LinuxWindow already destroyed");
        return;
    }
    
    glXMakeCurrent(display, None, glContext);
    glXDestroyContext(display, glContext);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    isDestroyed = true;
    logging::info("Destroying LinuxWindow");
}

bool LinuxWindow::update()
{
    XNextEvent(display, &lastEvent);

    if(lastEvent.type == Expose)
    {
        Renderer::render(display, window, &windowAtributes);
    }
    else if (lastEvent.type == KeyPress)
    {
        return false;
    }

    return true;
}

}