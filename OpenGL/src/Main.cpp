#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "include/Renderer.h"

#include "include/VertexBuffer.h"
#include "include/IndexBuffer.h"
#include "include/VertexArray.h"
#include "include/Shader.h"

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
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

    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        float positions[] = {
            -0.5f, -0.5f, // 0
            0.5f, -0.5f,  // 1
            0.5f, 0.5f,   // 2
            -0.5f, 0.5f   // 3
        };

        unsigned int indices[] = {// has to be unsigned
                                  0, 1, 2,
                                  2, 3, 0};

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        VertexArray va;
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));

        VertexBufferLayout layout;
        layout.push<float>(2);
        va.addBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        Shader shader("../res/shaders/basic.shader");
        shader.bind();
        shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        float r = 0.0f;
        float i = 0.05f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            shader.bind();
            shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

            va.bind();

            ib.bind();

            GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

            if (r > 1.0f)
            {
                i = -0.05f;
            }
            else if (r < 0.0f)
            {
                i = 0.05f;
            }

            r += i;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}
