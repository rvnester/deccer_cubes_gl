cmake_minimum_required(VERSION 3.26)

project(deccer_cubes_GL
LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

#FetchContent_Declare(
#    DilligentEngine
#    GIT_REPOSITORY https://github.com/DiligentGraphics/DiligentEngine.git
#    GIT_SHALLOW OFF
#)
#FetchContent_MakeAvailable(DilligentEngine)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_SHALLOW OFF
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_SHALLOW OFF
)
FetchContent_MakeAvailable(glm)
target_compile_definitions(glm INTERFACE
	GLM_FORCE_AVX2
	GLM_FORCE_RADIANS
)

FetchContent_Declare(
	glew
	GIT_REPOSITORY https://github.com/nigels-com/glew.git
	GIT_SHALLOW OFF
)
FetchContent_MakeAvailable(glew)

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	#GIT_SHALLOW OFF
	GIT_SHALLOW ON
	GIT_PROGRESS ON
)
#FetchContent_GetProperties(glad)
#if(NOT glad_POPULATED)
#	message("Fetching glad")
#	FetchContent_Populate(glad)
#	set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
#	set(GLAD_API "gl=4.6" CACHE STRING "API type or version pairs")
#	set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
#	add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
#endif()
FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
	message("Fetching glad")
	FetchContent_Populate(glad)
	set(GLAD_PROFILE "core")
	set(GLAD_API "gl=4.6")
	set(GLAD_GENERATOR "c")
	add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()


#set(GLAD_API "gl=3.3")

FetchContent_MakeAvailable(glad)

#set_target_properties(glad PROPERTIES
#	GLAD_PROFILE "core" 
#	GLAD_API "gl=4.5"
#)


add_executable(deccer_cubes_GL main.cpp)
target_compile_definitions(deccer_cubes_GL PRIVATE DECCER_CUBE_DEBUG_SWITCH)

#target_link_libraries(deccer_cubes_GL PRIVATE opengl32)
#target_link_libraries(deccer_cubes_GL PRIVATE glew32)
target_link_libraries(deccer_cubes_GL PRIVATE glad)
target_link_libraries(deccer_cubes_GL PRIVATE glfw)
target_link_libraries(deccer_cubes_GL PRIVATE glm::glm)

#target_include_directories(deccer_cubes_GL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include)
#target_link_directories(deccer_cubes_GL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/lib)
#target_link_libraries(deccer_cubes_GL glfw3)
#target_link_libraries(deccer_cubes_GL opengl32)