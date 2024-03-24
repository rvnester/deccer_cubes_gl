#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#pragma region GLFWCallbacks


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

#pragma endregion

#ifdef DECCER_CUBE_DEBUG_SWITCH
void APIENTRY OpenGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, 
    GLsizei length, const GLchar* message, const void* userParam)
{
    int x = 1;
    std::cout << id << "\n";
}
#endif

struct VertexPosColor
{
    glm::vec4 pos;
    glm::vec3 color;
};

#pragma region Shaders


std::string shader_vs =
R"(
#version 460 core

layout (location = 0) in vec4 vVertex;
layout (location = 1) in vec3 vColor;

layout (location = 0) out vec3 oColor;

out gl_PerVertex // must be used with seperable shader program
{
    vec4 gl_Position;
};

void main()
{
	gl_Position = vVertex;
    oColor = vColor;
}
)";

std::string shader_fs =
R"(
#version 460 core

layout (location = 0) in vec3 iColor;

layout (location = 0) out vec4 vFragColor;

void main()
{
	vFragColor = vec4(iColor, 1.0);
}
)";

enum class ShaderType
{
    Vertex,
    Fragment,
};

GLuint GetShader(ShaderType shaderType, const std::string& source)
{
    GLenum glShaderType;

    if (shaderType == ShaderType::Vertex)
    {
        glShaderType = GL_VERTEX_SHADER;
    }

    else if (shaderType == ShaderType::Fragment)
    {
        glShaderType = GL_FRAGMENT_SHADER;
    }

    GLuint shader = glCreateShader(glShaderType);

    const char* ptmp = source.c_str();
    glShaderSource(shader, 1, &ptmp, 0);

    GLint status;
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* infoLog = new GLchar[infoLogLength];
        glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
        std::cerr << "Compile log: " << infoLog << std::endl;
        delete[] infoLog;

        return -1;
    }

    return shader;
}

#pragma endregion

int main(void)
{
    glm::mat4 myMatrix = glm::translate(glm::mat4(1), glm::vec3(1, 5, 1));

    GLFWwindow* window;

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

    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef DECCER_CUBE_DEBUG_SWITCH
    glfwWindowHint(GLFW_CONTEXT_DEBUG, GLFW_TRUE);
#endif

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    SetGlfwCallbacks(window);

    if (!gladLoadGL()) 
    {
        std::cout<<"Failed to initialize OpenGL context\n";
        return -1;
    }

#ifdef DECCER_CUBE_DEBUG_SWITCH
    glDebugMessageCallback(OpenGLDebugCallback, "My Data");
#endif

    int backBufferWidth, backBufferHeight;
    glfwGetFramebufferSize(window, &backBufferWidth, &backBufferHeight);
    glViewport(0, 0, backBufferWidth, backBufferHeight);

    // Define vertrices
    std::vector<VertexPosColor> vertices;
    vertices.push_back({ glm::vec4( 0.0f,  0.5f, 0.0f, 1.0f), glm::vec3(0.6f, 0.3f, 1.0f)});
    vertices.push_back({ glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec3(1.0f, 0.3f, 0.1f)});
    vertices.push_back({ glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), glm::vec3(0.0f, 0.9f, 0.5f)});

    // Create vertex buffer
    GLuint vertexBuffer;
    glCreateBuffers(1, &vertexBuffer);
    // Could use either glNamedBufferStorage or glNamedBufferData
    // BufferStorage is immutable and can only called once for each buffer.
    // BufferData is not as optimized and will allocate for the same buffer
    // with each call.
    // An idea for a good use of BufferStorage is as a Dst of upload buffer.
    glNamedBufferData(vertexBuffer,
        vertices.size() * sizeof(VertexPosColor), vertices.data(), GL_STATIC_DRAW);

    // Create vertex layout
    GLuint vertexLayout;
    glCreateVertexArrays(1, &vertexLayout);

    // Define the vertex layout for position data
    int positionLocation = 0;
    glVertexArrayAttribFormat(vertexLayout, positionLocation, 4, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(vertexLayout, positionLocation, 0); // (location = positionLocation, binding = 0)
    glEnableVertexArrayAttrib(vertexLayout, positionLocation); // Don't forget to enable the attribute

    // Define the vertex layout for color data
    int colorLocation = 1;
    glVertexArrayAttribFormat(vertexLayout, colorLocation, 3, GL_FLOAT, GL_FALSE, offsetof(VertexPosColor, color));
    glVertexArrayAttribBinding(vertexLayout, colorLocation, 0); // (location = colorLocation, binding = 0)
    glEnableVertexArrayAttrib(vertexLayout, colorLocation); // Don't forget to enable the attribute

    // Bind vertex buffer to a vertex layout (aka use a buffer view with vertex buffer)
    glVertexArrayVertexBuffer(vertexLayout, 0, vertexBuffer, 0, sizeof(VertexPosColor));

    // Vertex Stage
    GLuint vertexShader = GetShader(ShaderType::Vertex, shader_vs);
    GLuint vertexProgram = glCreateProgram();
    glProgramParameteri(vertexProgram, GL_PROGRAM_SEPARABLE, GL_TRUE);
    glAttachShader(vertexProgram, vertexShader);
    //glBindAttribLocation(vertexProgram, 0, "vVertex");
    //glBindAttribLocation(vertexProgram, 1, "vColor");
    glLinkProgram(vertexProgram);
    GLint linkStatus;
    glGetProgramiv(vertexProgram, GL_LINK_STATUS, &linkStatus);
    glDetachShader(vertexProgram, vertexShader);
    glDeleteShader(vertexShader);

    // Fragment Stage
    GLuint fragmentShader = GetShader(ShaderType::Fragment, shader_fs);
    GLuint fragmentProgram = glCreateProgram();
    glProgramParameteri(fragmentProgram, GL_PROGRAM_SEPARABLE, GL_TRUE);
    glAttachShader(fragmentProgram, fragmentShader);
    //glBindFragDataLocation(fragmentProgram, 0, "iColor");
    glLinkProgram(fragmentProgram);
    glDetachShader(fragmentProgram, fragmentShader);
    glDeleteShader(fragmentShader);

    // Shaders use pipeline objects to mix&match shaders, instead of liking them
    GLuint programPipeline;
    glCreateProgramPipelines(1, &programPipeline);

    // Connect shader stages
    glUseProgramStages(programPipeline, GL_VERTEX_SHADER_BIT, vertexProgram);
    glUseProgramStages(programPipeline, GL_FRAGMENT_SHADER_BIT, fragmentProgram);

    //glClearColor(1, 1, 0, 1);
    float clearColor[] = { 1, 1, 0, 1 };
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearBufferfv(GL_COLOR, 0, clearColor);

        glBindProgramPipeline(programPipeline);

        glBindVertexArray(vertexLayout);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}