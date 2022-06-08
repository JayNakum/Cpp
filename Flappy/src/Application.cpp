#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/GLErrorManager.h"
#include "../include/Renderer.h"
#include "../include/VertexBuffer.h"
#include "../include/IndexBuffer.h"
#include "../include/VertexArray.h"
#include "../include/Shader.h"
#include "../include/Texture.h"

#include "../vendors/glm/glm.hpp"
#include "../vendors/glm/gtc/matrix_transform.hpp"

struct ScreenSize
{
    float width;
    float height;

    float topEdge() const { return (height / 2); }
    float bottomEdge() const { return ((height / 2) - height); }
    float rightEdge() const { return (width / 2); }
    float leftEdge() const { return ((width / 2) - width); }

} screenSize;

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
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); // GLFWmonitor *monitor = glfwGetPrimaryMonitor();

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    screenSize.width = mode->width;
    screenSize.height = mode->height;

    window = glfwCreateWindow(screenSize.width, screenSize.height, "Flappy Bird", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Initialize GLEW */
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        float positions[] = {
            -10.0f, -10.0f, 0.0f, 0.0f, // 0
            10.0f, -10.0f, 1.0f, 0.0f,  // 1
            10.0f, 10.0f, 1.0f, 1.0f,   // 2
            -10.0f, 10.0f, 0.0f, 1.0f   // 3
        };

        unsigned int indices[] = {
            0, 1, 2, // Triangle 1
            2, 3, 0  // Triangle 2
        };

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));

        VertexBufferLayout layout;
        layout.push<float>(2);
        layout.push<float>(2);
        va.addBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        glm::mat4 proj = glm::ortho(screenSize.leftEdge(), screenSize.rightEdge(), screenSize.bottomEdge(), screenSize.topEdge(), -1.0f, 1.0f);

        Shader shader("../res/shaders/basic.shader");
        shader.bind();
        // shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
        shader.setUniformMat4f("u_MVP", proj);
        Texture texture("../res/textures/logo.png");
        texture.bind();
        shader.setUniform1i("u_Texture", 0);

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        Renderer renderer;

        float r = 0.0f;
        float i = 0.05f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.clear();

            // shader.bind();
            // shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

            renderer.draw(va, ib, shader);

            if (r > 1.0f)
                i = -0.05f;

            else if (r < 0.0f)
                i = 0.05f;

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
