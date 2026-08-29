#include "WindowManager.hpp"

#include <stdexcept>

namespace Magika
{
WindowManager& WindowManager::Instance()
{
    static WindowManager instance;
    return instance;
}

void WindowManager::Initialize()
{
    // Initialize GLFW
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    // Create a GLFW window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // TODO: Should set these based on a Settings manager that is stored on disk
    m_window = glfwCreateWindow(800, 600, "Magika", nullptr, nullptr);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);
}

void WindowManager::Shutdown()
{
    if (m_window != nullptr)
        glfwDestroyWindow(m_window);

    glfwTerminate();
}

void WindowManager::Update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool WindowManager::IsWindowOpen() const
{
    if (!m_window)
        return false;

    return !glfwWindowShouldClose(m_window);
}
} // namespace Magika