#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <signal.h>
#define ASSERT(x) \
    if (!(x))     \
        raise(SIGTRAP);

#define GLCall(x)    \
    GLClearErrors(); \
    x;               \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearErrors()
{
    while (glGetError() != GL_NO_ERROR)
        ;
}

static bool GLLogCall(const char *function, const char *file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << ")"
                  << function << " "
                  << file << ":"
                  << line
                  << std::endl;
        return false;
    }
    return true;
}

int main(int, char**) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Pratice", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;


    float vertexPositions[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f
    };
    unsigned int vbo;
    GLCall(glGenBuffers(1, &vbo));
    GLCall(glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), vertexPositions, GL_STATIC_DRAW));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));

    unsigned int indexBuffer[] = {
        0, 1, 2
    };
    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
    unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(float), indexBuffer, GL_STATIC_DRAW));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));


    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        GLCall(glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr));

        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GLCall(glfwPollEvents());
    }
    glfwTerminate();
}
