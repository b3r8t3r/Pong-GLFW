#include <GLFW/glfw3.h>
#include "square_lib.h"

void drawSquare(){
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(-0.5, -0.5);
    glVertex2d(-0.5, 0.5);
    glVertex2d(0.5, 0.5);
    glVertex2d(0.5, -0.5);
    glEnd();
}