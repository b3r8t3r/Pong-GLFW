#include <stdio.h>
#include <GLFW/glfw3.h>
#include "square_lib.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// ===================================
//
// Program initialization function
//
// ===================================

int main(void) {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW application.\n");
        return -1;
    }

    // Create a window and OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Pong", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window.\n");
        glfwTerminate();
        return -1;
    }

    // Set the window as the current context
    glfwMakeContextCurrent(window);

    // Set the key callback function
    glfwSetKeyCallback(window, key_callback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render objects
        drawSquare();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();

    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}