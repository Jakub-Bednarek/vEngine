#include "WindowImpl.hpp"

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
    std::cout << "Initializing LinuxWindow\n";

    display = XOpenDisplay(nullptr);

    if(!display)
    {
        std::cout << "Failed to create display, exiting\n";
        exit(0);
    }

    rootWindow = DefaultRootWindow(display);

    if(!rootWindow)
    {
        std::cout << "Failed to create root window, exiting\n";
        exit(0);
    }

    visualInfo = glXChooseVisual(display, 0, glAttributes.data());

    if(!visualInfo)
    {
        std::cout << "Failed to set visualInfo for choosen display\n";
        exit(0);
    }
    
    std::cout << "Selected visualInfo with id: " << static_cast<void*>(visualInfo->visual) << '\n';
    
    colorMap = XCreateColormap(display, rootWindow, visualInfo->visual, AllocNone);
    setWindowAttributes.colormap = colorMap;
    setWindowAttributes.event_mask = ExposureMask | KeyPressMask;
    window = XCreateWindow(display, rootWindow, 0, 0, width, height, 0, visualInfo->depth, InputOutput, visualInfo->visual, CWColormap | CWEventMask, &setWindowAttributes);
    
    XMapWindow(display, window);
    XStoreName(display, window, "vEngine");

    glContext = glXCreateContext(display, visualInfo, nullptr, GL_TRUE);
    glXMakeCurrent(display, window, glContext);

    std::cout << "LinuxWindow created successfully\n";

    return true;
}

void LinuxWindow::clear()
{
    std::cout << "Clearing LinuxWindow\n";
}

void LinuxWindow::cleanUp()
{
    std::cout << "Cleaning up LinuxWindow\n";
}

void LinuxWindow::flush()
{
    std::cout << "Flushing LinuxWindow\n";
}

void LinuxWindow::destroy()
{
    glXMakeCurrent(display, None, glContext);
    glXDestroyContext(display, glContext);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    isDestroyed = true;

    std::cout << "Destroying LinuxWindow\n";
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
        destroy();
        return false;
    }

    return true;
}

}