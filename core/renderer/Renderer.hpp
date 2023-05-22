#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <GL/glu.h>
#include <GL/glx.h>

class Renderer
{
public:
    static void drawQuad()
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

    static void render(Display* display, Window& window, XWindowAttributes* windowAttributes)
    {
        XGetWindowAttributes(display, window, windowAttributes);
        glViewport(0, 0, windowAttributes->width, windowAttributes->height);
        drawQuad();
        glXSwapBuffers(display, window);
    }
};

#endif // RENDERER_HPP