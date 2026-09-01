#include "WindowManager.hpp"

#include "../Logging/LoggingManager.hpp"
#include "../Version.hpp"

#include <sstream>
#include <stdexcept>

namespace Magika
{
#pragma region Window Callbacks
void glfwErrorCallback(int error, const char* description)
{
    MK_LOG_ERROR("GLFW error {}: {}", error, description);
}
#pragma endregion

WindowManager& WindowManager::Instance()
{
    static WindowManager instance;
    return instance;
}

void WindowManager::Initialize()
{
    MK_LOG_TRACE("Initializing the Window Manager...");

    // Initialize GLFW
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    MK_LOG_TRACE("GLFW initialized successfully");

    // Create a Vulkan-capable GLFW window without an OpenGL context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // TODO: Should set these based on a Settings manager that is stored on disk
    std::stringstream windowTitle;
    windowTitle << "Magika " << PROJECT_VERSION;
    m_window = glfwCreateWindow(800, 600, windowTitle.str().c_str(), nullptr, nullptr);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    MK_LOG_TRACE("GLFW window created successfully");

    m_extensionCount = 0;
    m_extensions = glfwGetRequiredInstanceExtensions(&m_extensionCount);
    MK_LOG_TRACE("Vulkan instance extensions required by GLFW: {}", m_extensionCount);
    if (m_extensions == nullptr)
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        throw std::runtime_error("Failed to query Vulkan instance extensions");
    }

    MK_LOG_INFO("Window manager initialized successfully");
}

void WindowManager::Shutdown()
{
    MK_LOG_TRACE("Shutting down the Window Manager...");
    if (m_window != nullptr)
        glfwDestroyWindow(m_window);

    glfwTerminate();
    MK_LOG_INFO("Window manager shut down successfully");
}

void WindowManager::Update()
{
    glfwPollEvents();
}

bool WindowManager::IsWindowOpen() const
{
    if (!m_window)
        return false;

    return !glfwWindowShouldClose(m_window);
}
} // namespace Magika