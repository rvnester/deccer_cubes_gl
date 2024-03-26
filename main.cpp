#include <iostream>
#include <chrono>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

uniform PerRenderable
{
    mat4 World;
};


void main()
{
	gl_Position = World * vVertex;
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

void CheckLinkStatus(GLuint program)
{
    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        // The program is useless now. So delete it.
        glDeleteProgram(program);

        // Provide the infolog in whatever manner you deem best.
        // Exit with failure.
        throw std::exception("Failed to link program");
    }
}

#pragma endregion

int main(void)
{
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
    const GLchar* vertexShaderSource[] = { shader_vs.c_str() };
    GLuint vertexProgram = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, vertexShaderSource);
    CheckLinkStatus(vertexProgram);

    // Fragment Stage
    const GLchar* fragmentShaderSource[] = { shader_fs.c_str() };
    GLuint fragmentProgram = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, fragmentShaderSource);
    CheckLinkStatus(fragmentProgram);

    // Program pipelines allow us to mix and match different programs.
    GLuint programPipeline;
    glCreateProgramPipelines(1, &programPipeline);

    // Connect shader stages, aka build render pipeline
    glUseProgramStages(programPipeline, GL_VERTEX_SHADER_BIT, vertexProgram);
    glUseProgramStages(programPipeline, GL_FRAGMENT_SHADER_BIT, fragmentProgram);

    // Uniform buffer for the PerRenderable uniform block
    //
    
    // Query uniform buffer information
    std::string uniformBlockName{ "PerRenderable" };
    GLuint uniformBlockIndex = glGetUniformBlockIndex(vertexProgram, uniformBlockName.c_str());

    GLint uniformBlockSize;
    glGetActiveUniformBlockiv(vertexProgram, uniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uniformBlockSize);
    
    GLint uniformBlockBinding;
    glGetActiveUniformBlockiv(vertexProgram, uniformBlockIndex, GL_UNIFORM_BLOCK_BINDING, &uniformBlockBinding);

    // The above call with UNIFORM_BLOCK_BINDING already has the uniform buffer set to a specific binding index.
    // However in a real app we'd like to decide to which binding index the uniform block should be bound to.
    // This will allow us to set a globally shared uniform (aka constant) buffers and use then between shaders.
    // The following call doesn't change the binding index, but this is just here to show how it can be done.
    glUniformBlockBinding(vertexProgram, uniformBlockIndex, uniformBlockBinding);


    GLint numBlockActiveUniforms;
    glGetActiveUniformBlockiv(vertexProgram, uniformBlockIndex, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &numBlockActiveUniforms);

    // Query unformation about uniforms
    char* uniformNames[1] = { "World" };
    const int numUniforms = 1;
    GLuint uniformIndices[numUniforms];
    glGetUniformIndices(vertexProgram, numUniforms, uniformNames, uniformIndices);

    GLint uniformOffsets[numUniforms];
    glGetActiveUniformsiv(vertexProgram, numUniforms, uniformIndices, GL_UNIFORM_OFFSET, uniformOffsets);

    GLint uniformArrayStrides[numUniforms];
    glGetActiveUniformsiv(vertexProgram, numUniforms, uniformIndices, GL_UNIFORM_ARRAY_STRIDE, uniformArrayStrides);

    GLint uniformMatrixStrides[numUniforms];
    glGetActiveUniformsiv(vertexProgram, numUniforms, uniformIndices, GL_UNIFORM_MATRIX_STRIDE, uniformMatrixStrides);

    GLint uniformSizes[numUniforms];
    glGetActiveUniformsiv(vertexProgram, numUniforms, uniformIndices, GL_UNIFORM_SIZE, uniformSizes);

    GLint uniformTypes[numUniforms];
    glGetActiveUniformsiv(vertexProgram, numUniforms, uniformIndices, GL_UNIFORM_TYPE, uniformTypes);

    // Create uniform buffer
    GLuint uniformBuffer;
    glCreateBuffers(1, &uniformBuffer);

    // Notice the usage of BufferStorage and not BufferData.
    // We'll be calling this buffer every frame,
    // so we don't want the GPU to allocate a new memory for each call.
    // While the location is constant, we can still update the buffer's contents
    glNamedBufferStorage(uniformBuffer, uniformBlockSize, nullptr, GL_DYNAMIC_STORAGE_BIT);

    glBindBufferBase(GL_UNIFORM_BUFFER, uniformBlockIndex, uniformBuffer);

    glm::mat4 localMatrix(1.0f);
    glm::mat4 worldMatrix = glm::rotate(localMatrix, glm::degrees(30.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    //glClearColor(1, 1, 0, 1);
    float clearColor[] = { 1, 1, 0, 1 };

    /* Loop until the user closes the window */
    std::chrono::steady_clock::time_point prevTime = std::chrono::steady_clock::now();
    while (!glfwWindowShouldClose(window))
    {
        std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> diff = 
            std::chrono::duration_cast<std::chrono::milliseconds>(currTime - prevTime);
        std::cout << diff.count() << std::endl;

        float deltaTime = diff.count();

        const float rotationSpeed = 100.0f;
        static float rotationAmount = 0;
        rotationAmount += rotationSpeed * deltaTime;
        worldMatrix = glm::rotate(localMatrix, glm::radians(rotationAmount), glm::vec3(0.0f, 1.0f, 0.0f));

        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearBufferfv(GL_COLOR, 0, clearColor);

        glBindProgramPipeline(programPipeline);
        
        glBindVertexArray(vertexLayout);

        glNamedBufferSubData(uniformBuffer, 0, uniformBlockSize, glm::value_ptr(worldMatrix));
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        prevTime = currTime;
    }

    glDeleteVertexArrays(1, &vertexLayout);
    glDeleteBuffers(1, &uniformBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(vertexProgram);
    glDeleteProgram(fragmentProgram);
    glDeleteProgramPipelines(1, &programPipeline);

    glfwTerminate();
    return 0;
}