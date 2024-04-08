#include <iostream>
#include <chrono>
#include <unordered_map>
#include <cmath>
#include <random>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION    
#include <stb_image.h>

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
    switch (source)
    {
        case GL_DEBUG_SOURCE_API: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
        case GL_DEBUG_SOURCE_APPLICATION: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
        case GL_DEBUG_SOURCE_OTHER: std::cout << "source = GL_DEBUG_SOURCE_API"; break;
    }
    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR: std::cout << " type = GL_DEBUG_TYPE_ERROR"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << " type = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: std::cout << " type = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_PORTABILITY: std::cout << " type = GL_DEBUG_TYPE_PORTABILITY"; break;
        case GL_DEBUG_TYPE_PERFORMANCE: std::cout << " type = GL_DEBUG_TYPE_PERFORMANCE"; break;
        case GL_DEBUG_TYPE_MARKER: std::cout << " type = GL_DEBUG_TYPE_MARKER"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP: std::cout << " type = GL_DEBUG_TYPE_PUSH_GROUP"; break;
        case GL_DEBUG_TYPE_POP_GROUP: std::cout << " type = GL_DEBUG_TYPE_POP_GROUP"; break;
        case GL_DEBUG_TYPE_OTHER: std::cout << " type = GL_DEBUG_TYPE_OTHER"; break;
    }
    switch(severity)
    {
        case GL_DEBUG_SEVERITY_LOW: std::cout << " severity = GL_DEBUG_SEVERITY_LOW"; break;
        case GL_DEBUG_SEVERITY_MEDIUM: std::cout << " severity = GL_DEBUG_SEVERITY_MEDIUM"; break;
        case GL_DEBUG_SEVERITY_HIGH: std::cout << " severity = GL_DEBUG_SEVERITY_HIGH "; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << " severity = GL_DEBUG_SEVERITY_NOTIFICATION "; break;
    }

    int x = 1;
    std::cout << message << "\n";
}
#endif

struct VertexPosColor
{
    glm::vec4 pos;
    glm::vec3 color;
};

struct VertexPosColorUv
{
    glm::vec4 pos;
    glm::vec3 color;
    glm::vec2 uv;
};

#pragma region Shaders

std::string shader_vs =
R"(
#version 460 core
//#extension GL_NV_uniform_buffer_std430_layout : enable

layout (location = 0) in vec4 vVertex;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vUV;

layout (location = 0) out vec3 oColor;
layout (location = 1) out vec2 oUV;
layout (location = 2) out float oUseTexture;

out gl_PerVertex // must be used with seperable shader program
{
    vec4 gl_Position;
};

layout(std140) buffer PerRenderable
{
    mat4 World[];
};

uniform Matrices
{
    mat4 View;
    mat4 Projection;
};

void main()
{
    gl_Position = Projection * View * World[gl_InstanceID] * vVertex;
    oColor = vColor;
    oUV = vUV;
    oUseTexture = gl_InstanceID % 2;
}
)";

std::string shader_fs =
R"(
#version 460 core

layout (location = 0) in vec3 iColor;
layout (location = 1) in vec2 iUV;
layout (location = 2) in float iUseTexture;

layout (location = 0) out vec4 vFragColor;

layout (location = 0) uniform sampler2D sampler;

void main()
{
	//vFragColor = vec4(iColor, 1.0);
    //vFragColor = texture(sampler, iUV);
    vFragColor = (1 - iUseTexture) * texture(sampler, iUV) + iUseTexture * vec4(iColor, 1.0);
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
        return;
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
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(OpenGLDebugCallback, "My Data");
#endif

    int backBufferWidth, backBufferHeight;
    glfwGetFramebufferSize(window, &backBufferWidth, &backBufferHeight);
    glViewport(0, 0, backBufferWidth, backBufferHeight);

    // Define vertrices
    std::vector<VertexPosColorUv> vertices;
    vertices.push_back({ glm::vec4( 0.0f,  0.5f, 0.0f, 1.0f), glm::vec3(0.6f, 0.3f, 1.0f), glm::vec2(0.5f, 1.0f)});
    vertices.push_back({ glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec3(1.0f, 0.3f, 0.1f), glm::vec2(0.0f, 0.0f)});
    vertices.push_back({ glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), glm::vec3(0.0f, 0.9f, 0.5f), glm::vec2(1.0f, 0.0f)});
    

    // Create vertex buffer
    GLuint vertexBuffer;
    glCreateBuffers(1, &vertexBuffer);
    // Could use either glNamedBufferStorage or glNamedBufferData
    // BufferStorage is immutable and can only called once for each buffer.
    // BufferData is not as optimized and will allocate for the same buffer
    // with each call.
    // An idea for a good use of BufferStorage is as a Dst of upload buffer.
    glNamedBufferData(vertexBuffer,
        vertices.size() * sizeof(VertexPosColorUv), vertices.data(), GL_STATIC_DRAW);

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
    glVertexArrayAttribFormat(vertexLayout, colorLocation, 3, GL_FLOAT, GL_FALSE, offsetof(VertexPosColorUv, color));
    glVertexArrayAttribBinding(vertexLayout, colorLocation, 0); // (location = colorLocation, binding = 0)
    glEnableVertexArrayAttrib(vertexLayout, colorLocation); // Don't forget to enable the attribute

    // Define the vertex layout for uv coordinates
    int uvLocation = 2;
    glVertexArrayAttribFormat(vertexLayout, uvLocation, 2, GL_FLOAT, GL_FALSE, offsetof(VertexPosColorUv, uv));
    glVertexArrayAttribBinding(vertexLayout, uvLocation, 0);
    glEnableVertexArrayAttrib(vertexLayout, uvLocation);

    // Bind vertex buffer to a vertex layout (aka use a buffer view with vertex buffer)
    glVertexArrayVertexBuffer(vertexLayout, 0, vertexBuffer, 0, sizeof(VertexPosColorUv));

    
    // Load Image Data
    char const* filename = "../assets/marioimage.jpg";
    int width, height;
    int channelsInFile;
    const int desiredChannels = 0;
    stbi_uc* imageData = stbi_load(filename, &width, &height, &channelsInFile, desiredChannels);

    // Create Texture
    GLuint texture;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    glTextureStorage2D(texture, 1, GL_RGB16, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, (void*)imageData);

    stbi_image_free(imageData);

    glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_R, GL_REPEAT);

    // Remember to bind the texture to texture unit
    glBindTextureUnit(0, texture);

    // Texture Sampler
    // We don't have to create samplers, we already defined how we want to texture to be sampled
    // with the GlTextureParameteri functions above. However, by creating different samplers we can
    // seperate the texture from how it's samples by rebinding with different samplers.
    // Think of it like the seperation between a vertex buffer (the texture) and a vertex layout (the sampler).
    GLuint sampler;
    glCreateSamplers(1, &sampler);

    glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glSamplerParameteri(sampler, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    // Don't forget to bind the sampler to a texture unit
    glBindSampler(0, sampler);

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

    
    // Create a Shader Storage Buffer Object, ssob
    GLuint shaderStorageBuffer;
    glCreateBuffers(1, &shaderStorageBuffer);

    const int totalNumTriangles = 32000;
    const int shaderStorageBufferSize = sizeof(glm::mat4) * totalNumTriangles;
    glNamedBufferStorage(shaderStorageBuffer, shaderStorageBufferSize, nullptr, GL_DYNAMIC_STORAGE_BIT | GL_MAP_WRITE_BIT);

    GLuint shaderStorageBufferIndex = 0;
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, shaderStorageBufferIndex, shaderStorageBuffer);

    GLuint shaderStorageBufferBinding = 0;
    glShaderStorageBlockBinding(vertexProgram, shaderStorageBufferIndex, shaderStorageBufferBinding);
    

    glm::mat4 localMatrix(1.0f);

    // Camera
    // We'll create a new uniform buffer specifically for view and project matrices
    // Query matrices uniform block
    std::string matricesUniformBlockName{ "Matrices" };
    GLuint matricesUniformBlockIndex = glGetUniformBlockIndex(vertexProgram, matricesUniformBlockName.c_str());

    GLint matricesUniformBlockSize;
    glGetActiveUniformBlockiv(vertexProgram, matricesUniformBlockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &matricesUniformBlockSize);

    // Don't forget to bind the uniform block index to the binding slot
    GLint matricesUniformBlockBinding = 0;
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

    GLint matricesUniformMatrixStrides[numMatricesUniforms];
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_MATRIX_STRIDE, matricesUniformMatrixStrides);

    GLint matricesUniformSizes[numMatricesUniforms]; 
    glGetActiveUniformsiv(vertexProgram, numMatricesUniforms, matricesUniformIndices, GL_UNIFORM_SIZE, matricesUniformSizes);

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

    const int numberOfDimensions = 3; // box has 3 dimentions
    float power = std::powf(totalNumTriangles, 1.0f / 3.0f);
    int iterationsPerDimension = std::ceil(power);

    std::random_device randomDevice;
    std::mt19937 posGen(randomDevice());
    std::uniform_real_distribution<> randomPosition(0.0f, 512.0f);

    std::random_device randomeDevice;
    std::mt19937 rotGen(randomeDevice());
    std::uniform_real_distribution<> randomRotation(0.0, 360.0);

    std::vector<glm::mat4> positions(totalNumTriangles);
    std::vector<float> rotationsAmount(totalNumTriangles);

    for (int i = 0; i < totalNumTriangles; i++)
    {
        //positions[i] = glm::mat4(1.0f);
        //positions[i][3] = glm::vec4(randomPosition(posGen), randomPosition(posGen), randomPosition(posGen), 1.0f);
        //glm::column(positions[i], 3) = glm::vec4(randomPosition(posGen), randomPosition(posGen), randomPosition(posGen), 1.0f);
        positions[i] = glm::translate(glm::mat4(1.0f), glm::vec3(randomPosition(posGen), randomPosition(posGen), randomPosition(posGen)));
        rotationsAmount[i] = randomRotation(rotGen);
    }

    std::vector<glm::mat4> worldMatrices(totalNumTriangles);

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
        if (cameraPitchAmount > 89.0f)
        {
            cameraPitchAmount = 89.0f;
        }
        else if (cameraPitchAmount < -89.0f)
        {
            cameraPitchAmount = -89.0f;
        }

        glm::quat cameraRotationY = glm::angleAxis(glm::radians(-cameraYawAmount), upVector);
        glm::quat cameraRotationX = glm::angleAxis(glm::radians(-cameraPitchAmount), rightVector);

        // Camera Forward Movement
        glm::vec3 cameraForward = forwardVector;
        //cameraForward = cameraRotationY * cameraForward;
        cameraForward = cameraRotationY * cameraRotationX * cameraForward;
        gCameraPosition += cameraForward * cameraSpeed * deltaTime * (float)gInputForward;

        // Camera Horizontal Movement
        glm::vec3 cameraRight = rightVector;
        cameraRight = cameraRotationY * cameraRight;
        gCameraPosition += cameraRight * cameraSpeed * deltaTime * (float)gInputHorizontal;

        // Camera Vertical Movement
        glm::vec3 cameraUp = upVector;
        cameraUp = cameraRotationY * cameraRotationX * cameraUp;
        gCameraPosition += cameraUp * cameraSpeed * deltaTime * (float)gInputVertical;

        // Camera
        viewMatrix = glm::lookAtRH(gCameraPosition, gCameraPosition - cameraForward, camUp);

        // Update Matrices Uniform Buffer
        unsigned int viewMatrixIndex = matricesNamesIndices["View"];
        glNamedBufferSubData(matricesUniformBuffer,
            // The offsets come in the wrong order for some reason
            matricesUniformOffsets[0], matricesUniformSizes[viewMatrixIndex] * sizeof(glm::mat4),
            glm::value_ptr(viewMatrix));

        unsigned int projectionMatrixIndex = matricesNamesIndices["Projection"];
        glNamedBufferSubData(matricesUniformBuffer,
            matricesUniformOffsets[1], matricesUniformSizes[projectionMatrixIndex] * sizeof(glm::mat4),
            glm::value_ptr(projectionMatrix));

        // Triangles
        glBindProgramPipeline(programPipeline);
        glBindVertexArray(vertexLayout);

        glm::mat4 worldMatrix = glm::scale(localMatrix, glm::vec3(10, 10, 1));
        //glNamedBufferSubData(uniformBuffer, 0, uniformBlockSize, glm::value_ptr(worldMatrix));

        /* Render here */
        glClearBufferfv(GL_COLOR, 0, clearColor);

        const float rotationSpeed = 10.0f;
        static float rotationAmount = 0;

        glm::mat4 localScale = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 10.0f, 1.0f));
        glm::mat4 boxTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(-512 / 2, -512 / 2, -512 / 2));

        for (int i = 0; i < totalNumTriangles; i++)
        {
            rotationsAmount[i] += rotationSpeed * deltaTime;
            glm::mat4 localRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotationsAmount[i]), upVector);
            worldMatrices[i] = boxTranslation * positions[i] * localRotation * localScale;
        }

        glNamedBufferSubData(shaderStorageBuffer, 0, sizeof(glm::mat4) * totalNumTriangles, worldMatrices.data());
            
        glDrawArraysInstanced(GL_TRIANGLES, 0, 3, totalNumTriangles);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        prevTime = currTime;
        glfwSetTime(0);
    }

    glDeleteSamplers(1, &sampler);
    glDeleteTextures(1, &texture);
    glDeleteVertexArrays(1, &vertexLayout);
    glDeleteBuffers(1, &matricesUniformBuffer);
    glDeleteBuffers(1, &shaderStorageBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(vertexProgram);
    glDeleteProgram(fragmentProgram);
    glDeleteProgramPipelines(1, &programPipeline);

    glfwTerminate();
    return 0;
}