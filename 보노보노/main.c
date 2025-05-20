#pragma comment(lib, "opengl32.lib");
#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.1415926535f

typedef struct
{
    float x, y;
} Vec2;

typedef struct
{
    Vec2 position;
    float rotation;    //
    Vec2 scale;
} Transform;

typedef struct
{
    Transform transform;
} Triangle;

void draw_triangle(Triangle* tri)
{
    glPushMatrix();

    glTranslatef(tri->transform.position.x, tri->transform.position.y, 0.0f);
    glRotatef(tri->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(tri->transform.scale.x, tri->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glPopMatrix();
}

typedef struct
{
    Transform transform;
} Square;

void draw_square(Square* sq)
{
    glPushMatrix();

    glTranslatef(sq->transform.position.x, sq->transform.position.y, 0.0f);
    glRotatef(sq->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(sq->transform.scale.x, sq->transform.scale.y, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    glPopMatrix();
}

typedef struct
{
    Transform transform;
    int segments;
} Circle;

void draw_circle(Circle* c)
{
    glPushMatrix();

    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    //glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= c->segments; ++i)
    {
        float angle = 2.0f * PI * i / c->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }

    glEnd();

    glPopMatrix();
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(537, 445, "OpenGL C Demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1); // 2D



    // 파란 얼굴 원
    Circle bg = { {{0.0f, 0.0f}, 0, {10.0f, 10.0f}}, 64 };
    Circle edge = { {{0.0f, 0.0f}, 0, {1.60893f, 1.74382f}}, 64 };
    Circle face = { {{0.0f, 0.0f}, 0, {1.59404f, 1.72584f}}, 64 };

    Circle left_eye = { {{-0.66f, 0.2f}, 0, {0.12662f, 0.14382f}}, 32 };
    Circle right_eye = { {{0.6f, 0.17f}, 0, {0.12662f, 0.14831f}}, 32 };

    // 코 (중간 검은 원)
    Circle nose = { {{0.03, -0.1f}, 0, {0.25325f, 0.25617f}}, 32 };

    Circle mouth_left = { {{-0.11f, -0.3f}, 0, {0.33147f, 0.33258f}}, 32 };
    Circle mouth_right = { {{0.18f, -0.3f}, 0, {0.33147f, 0.33258f}}, 32 };


    while (!glfwWindowShouldClose(window))
    {
        //float time = (float)glfwGetTime();

        // ?? ?
        //tri.transform.position.x = sinf(time);
        //sq.transform.rotation = time;
        //cir.transform.scale.x = 1.0f + 0.5f * sinf(time);

        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&bg);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&edge);

        glColor3f(0.0f, 0.439f, 0.753f);
        draw_circle(&face);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&left_eye);
        draw_circle(&right_eye);


        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&mouth_left);
        draw_circle(&mouth_right);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&nose);

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);

        glVertex2f(-0.18f, -0.19f); glVertex2f(-0.41f, -0.12f);
        glVertex2f(-0.2f, -0.30f); glVertex2f(-0.42f, -0.30f);
        glVertex2f(-0.17f, -0.36f); glVertex2f(-0.41f, -0.44f);

        glVertex2f(0.21f, -0.21f); glVertex2f(0.45f, -0.13f);
        glVertex2f(0.21f, -0.30f); glVertex2f(0.46f, -0.30f);
        glVertex2f(0.21f, -0.38f); glVertex2f(0.45f, -0.43f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}