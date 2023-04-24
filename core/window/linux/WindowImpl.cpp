#include "WindowImpl.hpp"
#include "logging/Logger.hpp"

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

void drawQuad()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 20.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.75f, -0.75, 0.0);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.75f, -0.75, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.75f, 0.75, 0.0);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-0.75f, 0.75, 0.0);
    glEnd();
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
        XGetWindowAttributes(display, window, &windowAtributes);
        glViewport(0, 0, windowAtributes.width, windowAtributes.height);
        drawQuad();
        glXSwapBuffers(display, window);
    }
    else if (lastEvent.type == KeyPress)
    {
        return false;
    }

    return true;
}

}