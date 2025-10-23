cmake_minimum_required(VERSION 3.31)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(thirdParty/glm)

add_executable(VulkanRenderer main.cpp)

# 添加 GLFW3 预编译库
find_package(glfw3 3.4 REQUIRED)
# Vulkan
find_package(Vulkan REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw Vulkan::Vulkan glm-header-only)
# copy the shader files to the cmake-build-debug folder
file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})