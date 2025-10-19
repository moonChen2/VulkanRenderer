cmake_minimum_required(VERSION 3.31)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 23)

set(GLM_INCLUDE_DIRS "/opt/homebrew/Cellar/glm/1.0.2/include/glm")

add_executable(VulkanRenderer main.cpp)

# 添加 GLFW3 预编译库
find_package(glfw3 3.4 REQUIRED)
# GLM
include_directories(${GLM_INCLUDE_DIRS})

# Vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw Vulkan::Vulkan)
#include_directories(${Vulkan_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})

# copy the shader files to the cmake-build-debug folder
file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})