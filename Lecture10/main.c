#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <math.h>

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        int segments = 100;
        float radius = 0.5f;
        float pi = 3.1415926f;

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        for (int i = 0; i <= segments; i++) {
            float a = 2.0f * pi * i / segments;
            float b = 2.0f * pi * (i + 1) / segments;
            float x1 = radius * cosf(a);
            float y1 = radius * sinf(a);
            float x2 = radius * cosf(b);
            float y2 = radius * sinf(b);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
