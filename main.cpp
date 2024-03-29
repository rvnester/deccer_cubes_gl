#include <iostream>
#include <chrono>
#include <unordered_map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

int gInputForward = 0;
int gInputHorizontal = 0;
int gInputVertical = 0;

bool gInputRightMouseDown = false;
double gInputPrevMouseX = 0.0;
double gInputPrevMouseY = 0.0;
double gInputDeltaMouseX = 0.0;
double gInputDeltaMouseY = 0.0;

glm::vec3 gCameraPosition;

std::ostream& operator<<(std::ostream& output, const glm::vec3& vector)
{
    output << "x:" << vector.x << " y:" << vector.y << " z:" << vector.z;
    return output;
}

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

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        gInputForward = -1;
    }
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        gInputForward = 1;
    }
    
    if((key == GLFW_KEY_W || key == GLFW_KEY_S) && action == GLFW_RELEASE)
    {
        gInputForward = 0;
    }

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        gInputHorizontal = -1;
    }
    else if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        gInputHorizontal = 1;
    }

    if ((key == GLFW_KEY_A || key == GLFW_KEY_D) && action == GLFW_RELEASE)
    {
        gInputHorizontal = 0;
    }

    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        gInputVertical = 1;
    }
    else if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        gInputVertical = -1;
    }

    if ((key == GLFW_KEY_E || key == GLFW_KEY_Q) && action == GLFW_RELEASE)
    {
        gInputVertical = 0;
    }
}

void OnCharKey(GLFWwindow* window, unsigned int codepoint)
{

}

void OnCharModsKey(GLFWwindow* window, unsigned int codepoint, int mods)
{

}

bool gFirstTimeMouseDrag = false;

void OnMouseButton(GLFWwindow* window, int button, int action, int mods)
{
    if (button == 1)
    {
        if (action == GLFW_PRESS)
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            gInputRightMouseDown = true;

            double mousePosX, mousePosY;
            glfwGetCursorPos(window, &mousePosX, &mousePosY);
            gInputPrevMouseX = mousePosX;
            gInputPrevMouseY = mousePosY;
        }
        if (action == GLFW_RELEASE)
        {
            gInputDeltaMouseX = 0.0f;
            gInputDeltaMouseY = 0.0f;
            gInputRightMouseDown = false;
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
    }
}

void OnMouseMove(GLFWwindow* window, double x, double y)
{
    if (!gInputRightMouseDown)
    {
        return;
    }
    
    gInputDeltaMouseX = x - gInputPrevMouseX;
    gInputDeltaMouseY = y - gInputPrevMouseY;

    gInputPrevMouseX = x;
    gInputPrevMouseY = y;
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
    glViewport(0, 0, width, height);
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
//#extension GL_NV_uniform_buffer_std430_layout : enable

layout (location = 0) in vec4 vVertex;
layout (location = 1) in vec3 vColor;

layout (location = 0) out vec3 oColor;

out gl_PerVertex // must be used with seperable shader program
{
    vec4 gl_Position;
};

layout(std140) uniform PerRenderable
{
    mat4 World;
};

uniform Matrices
{
    mat4 View;
    mat4 Projection;
};

void main()
{
	gl_Position = Projection * View * World * vVertex;
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
    std::string uniformBlockName{ "PerRenderable"};
    GLuint uniformBlockIndex = glGetUniformBlockIndex(vertexProgram, uniformBlockName.c_str());

    GLint uniformBlockSize;
    glGetActiveUniformBlockiv(vertexProgram, uniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uniformBlockSize);
    
    GLint uniformBlockBinding;
    glGetActiveUniformBlockiv(vertexProgram, uniformBlockIndex, GL_UNIFORM_BLOCK_BINDING, &uniformBlockBinding);

    // The above call with UNIFORM_BLOCK_BINDING already has the uniform buffer set to a specific binding index.
    // However in a real app we'd like to decide to which binding index the uniform block should be bound to.
    // This will allow us to set a globally shared uniform (aka constant) buffers and use then between shaders.
    // The following call doesn't change the binding index, but this is just here to show how it can be done.
    uniformBlockBinding = 1;
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

    glBindBufferBase(GL_UNIFORM_BUFFER, uniformBlockBinding, uniformBuffer);

    glm::mat4 localMatrix(1.0f);
    glm::mat4 worldMatrix = glm::rotate(localMatrix, glm::degrees(30.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    // Camera
    // We'll create a new uniform buffer specifically for view and project matrices
    // Query matrices uniform block
    std::string matricesUniformBlockName{ "Matrices" };
    GLuint matricesUniformBlockIndex = glGetUniformBlockIndex(vertexProgram, matricesUniformBlockName.c_str());

    GLint matricesUniformBlockSize;
    glGetActiveUniformBlockiv(vertexProgram, matricesUniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &matricesUniformBlockSize);

    GLint matricesUniformBlockBinding;
    glGetActiveUniformBlockiv(vertexProgram, matricesUniformBlockIndex, GL_UNIFORM_BLOCK_BINDING, &matricesUniformBlockBinding);

    // Don't forget to bind the uniform block index to the binding slot
    matricesUniformBlockBinding = 0;
    glUniformBlockBinding(vertexProgram, matricesUniformBlockIndex, matricesUniformBlockBinding);

    // Query info about the uniforms in the matrices uniform block
    char* matricesUniformNames[2] = { "View", "Projection" };
    const int numMatricesUniforms = 2;
    GLuint matricesUniformIndices[numMatricesUniforms];
    glGetUniformIndices(vertexProgram, numMatricesUniforms, matricesUniformNames, matricesUniformIndices);

    std::unordered_map<std::string, unsigned int> matricesNamesIndices;

    for (int i = 0; i < numMatricesUniforms; i++)
    {
        std::string name{ matricesUniformNames[i] };
        unsigned int index = matricesUniformIndices[i];
        matricesNamesIndices[name] = index;
    }

    GLint matricesUniformOffsets[numMatricesUniforms];
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_OFFSET, matricesUniformOffsets);

    GLint matricesUniformArrayStrides[numMatricesUniforms];
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_ARRAY_STRIDE, matricesUniformArrayStrides);

    GLint matricesUniformMatrixStrides[numMatricesUniforms];
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_MATRIX_STRIDE, matricesUniformMatrixStrides);

    GLint matricesUniformSizes[numMatricesUniforms]; 
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_SIZE, matricesUniformSizes);

    GLint matricesUniformTypes[numMatricesUniforms];
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_TYPE, matricesUniformTypes);

    // Create uniform buffer
    GLuint matricesUniformBuffer;
    glCreateBuffers(1, &matricesUniformBuffer);
    glNamedBufferStorage(matricesUniformBuffer, matricesUniformBlockSize, nullptr, GL_DYNAMIC_STORAGE_BIT);

    // Don't forget to bind the uniform buffer to the binding slot
    glBindBufferBase(GL_UNIFORM_BUFFER, matricesUniformBlockBinding, matricesUniformBuffer);

    // View matrix
    //glm::vec3 camPosition(0.0f, 0.0f, -30.0f);
    gCameraPosition = glm::vec3(0.0f, 0.0f, 30.0f);
    glm::vec3 camTarget(0.0f, 0.0f, 1.0f);
    glm::vec3 camUp(0.0f, 1.0f, 0.0f);
    glm::mat4 viewMatrix = glm::lookAtRH(gCameraPosition, camTarget, camUp);

    // Projection matrix
    glm::mat4 projectionMatrix = glm::perspectiveRH_NO(glm::radians(60.0f), 640.0f / 480.0f, 0.1f, 1000.0f);

    //glClearColor(1, 1, 0, 1);
    float clearColor[] = { 1, 1, 0, 1 };

    /* Loop until the user closes the window */
    std::chrono::steady_clock::time_point prevTime = std::chrono::steady_clock::now();
    while (!glfwWindowShouldClose(window))
    {
        std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> diff = 
            std::chrono::duration_cast<std::chrono::milliseconds>(currTime - prevTime);

        float deltaTime = diff.count();

        // Update Camera
        const float cameraSpeed = 20.0f;
        const float cameraRotationSpeed = 20.0f;
        static float cameraYawAmount = 0.0f;
        static float cameraPitchAmount = 0.0f;
        
        const glm::vec3 rightVector(1.0f, 0.0f, 0.0f);
        const glm::vec3 upVector(0.0f, 1.0f, 0.0f);
        const glm::vec3 forwardVector(0.0f, 0.0f, 1.0f);

        // Camera Y Rotation, Yaw
        cameraYawAmount += cameraRotationSpeed * deltaTime * gInputDeltaMouseX;
        cameraPitchAmount += cameraRotationSpeed * deltaTime * gInputDeltaMouseY;

        std::cout << "cameraYawAmount " << gInputDeltaMouseY << std::endl;

        glm::quat cameraRotationY = glm::angleAxis(glm::radians(-cameraYawAmount), upVector);
        glm::quat cameraRotationX = glm::angleAxis(glm::radians(-cameraPitchAmount), rightVector);

        // Camera Forward Movement
        glm::vec3 cameraForward = forwardVector;
        //cameraForward = cameraRotationY * cameraForward;
        cameraForward = cameraRotationY * cameraRotationX * cameraRotationY * cameraForward;
        gCameraPosition += cameraForward * cameraSpeed * deltaTime * (float)gInputForward;

        // Camera Horizontal Movement
        glm::vec3 cameraRight = rightVector;
        cameraRight = cameraRotationY * cameraRight;
        gCameraPosition += cameraRight * cameraSpeed * deltaTime * (float)gInputHorizontal;

        // Camera Vertical Movement
        glm::vec3 cameraUp = upVector;
        gCameraPosition += cameraUp * cameraSpeed * deltaTime * (float)gInputVertical;

        // Camera
        viewMatrix = glm::lookAtRH(gCameraPosition, gCameraPosition - cameraForward, camUp);

        // It's probably slower to update one uniform at a time instead of an entire buffer in one go
        // but it's fine for now, it's part of a learing process anyway
        //viewMatrix = glm::column(viewMatrix, 3, glm::vec4(gCameraPosition, 1.0f));
        unsigned int viewMatrixIndex = matricesNamesIndices["View"];
        glNamedBufferSubData(matricesUniformBuffer,
            // The offsets come in the wrong order for some reason
            matricesUniformOffsets[0], matricesUniformSizes[viewMatrixIndex] * sizeof(glm::mat4),
            glm::value_ptr(viewMatrix));

        unsigned int projectionMatrixIndex = matricesNamesIndices["Projection"];
        glNamedBufferSubData(matricesUniformBuffer,
            matricesUniformOffsets[1], matricesUniformSizes[projectionMatrixIndex] * sizeof(glm::mat4),
            glm::value_ptr(projectionMatrix));

        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearBufferfv(GL_COLOR, 0, clearColor);
        
        // Triangles
        glBindProgramPipeline(programPipeline);
        glBindVertexArray(vertexLayout);
        
        for (int i = 0; i < 20; i++)
        {
            const float rotationSpeed = 20.f;
            static float rotationAmount = 0;

            rotationAmount += rotationSpeed * deltaTime;
            worldMatrix = glm::rotate(localMatrix, glm::radians(rotationAmount), glm::vec3(0.0f, 1.0f, 0.0f));

            worldMatrix = glm::scale(worldMatrix, glm::vec3(10, 10, 1));
            
            const float radius = 30.0f;
            glm::vec3 position(radius, 0.0f, 0.0f);
            glm::mat4 translation = glm::translate(glm::mat4(1.0f), position);
            glm::mat4 rotatedAngle = glm::rotate(glm::mat4(1.0f), glm::radians(360.0f / 20 * i), upVector);

            worldMatrix = rotatedAngle * translation * worldMatrix;
            
            glNamedBufferSubData(uniformBuffer, 0, uniformBlockSize, glm::value_ptr(worldMatrix));

            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

        //glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        prevTime = currTime;
        glfwSetTime(0);
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