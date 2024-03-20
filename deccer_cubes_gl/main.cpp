#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

void OnGlfwError(int error, const char* description)
{
    std::cout << "Error: " << error << " " << description << std::endl;
}

void OnKey(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void OnCharKey(GLFWwindow* window, unsigned int codepoint)
{

}

void OnCharModsKey(GLFWwindow* window, unsigned int codepoint, int mods)
{

}

void OnMouseButton(GLFWwindow* window, int button, int action, int mods)
{

}

void OnMouseMove(GLFWwindow* window, double x, double y)
{

}

void OnMouseScroll(GLFWwindow* window, double xOffset, double yOffset)
{

}

void OnMouseEnter(GLFWwindow* window, int entered)
{

}

void OnDragAndDrop(GLFWwindow* window, int numPaths, const char* paths[])
{

}

void OnWindowMove(GLFWwindow* window, int x, int y)
{

}

void OnWindowSize(GLFWwindow* window, int width, int height)
{

}

void OnWindowClose(GLFWwindow* window)
{

}

void OnWindowNeedRefresh(GLFWwindow* window)
{

}

void OnWindowFocus(GLFWwindow* window, int focused)
{

}

void OnWindowIconify(GLFWwindow* window, int iconified)
{

}

void OnWindowMaximize(GLFWwindow* window, int maxmized)
{

}

void OnFramebufferResize(GLFWwindow* window, int width, int height)
{

}

void OnWindowContentScale(GLFWwindow* window, float xScale, float yScale)
{

}

void SetGlfwCallbacks(GLFWwindow* targetWindow)
{
    glfwSetErrorCallback(OnGlfwError);
    glfwSetKeyCallback(targetWindow, OnKey);
    glfwSetCharCallback(targetWindow, OnCharKey);
    glfwSetCharModsCallback(targetWindow, OnCharModsKey);
    glfwSetMouseButtonCallback(targetWindow, OnMouseButton);
    glfwSetCursorPosCallback(targetWindow, OnMouseMove);
    glfwSetCursorEnterCallback(targetWindow, OnMouseEnter);
    glfwSetScrollCallback(targetWindow, OnMouseScroll);
    glfwSetDropCallback(targetWindow, OnDragAndDrop);
    glfwSetWindowPosCallback(targetWindow, OnWindowMove);
    glfwSetWindowSizeCallback(targetWindow, OnWindowSize);
    glfwSetWindowCloseCallback(targetWindow, OnWindowClose);
    glfwSetWindowRefreshCallback(targetWindow, OnWindowNeedRefresh);
    glfwSetWindowFocusCallback(targetWindow, OnWindowFocus);
    glfwSetWindowIconifyCallback(targetWindow, OnWindowIconify);
    glfwSetWindowMaximizeCallback(targetWindow, OnWindowMaximize);
    glfwSetFramebufferSizeCallback(targetWindow, OnFramebufferResize);
    glfwSetWindowContentScaleCallback(targetWindow, OnWindowContentScale);
}

int main(void)
{
    glm::mat4 myMatrix = glm::translate(glm::mat4(1), glm::vec3(1, 5, 1));

    GLFWwindow* window;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 5);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    SetGlfwCallbacks(window);

    int version = gladLoadGL();
    if (version == 0) {
        std::cout<<"Failed to initialize OpenGL context\n";
        return -1;
    }

    int backBufferWidth, backBufferHeight;
    glfwGetFramebufferSize(window, &backBufferWidth, &backBufferHeight);
    glViewport(0, 0, backBufferWidth, backBufferHeight);

    glClearColor(1, 1, 0, 1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}