#include "Application.hpp"

#include "Logging/LoggingManager.hpp"
#include "Window/WindowManager.hpp"

namespace Magika
{
Application& Application::Instance()
{
    static Application instance;
    return instance;
}

void Application::Run()
{
    Initialize();

    // TODO: Implement a proper main loop with event handling, timing, and rendering
    // TODO: Update loop to use window as loop control
    // TODO: Change this to be an event based decision
    while (WindowManager::Instance().IsWindowOpen())
    {
        // TODO: Rendering
        glClear(GL_COLOR_BUFFER_BIT);

        Update();
    }

    Shutdown();
}

void Application::Initialize()
{
    LoggingManager::Instance().Initialize();
    WindowManager::Instance().Initialize();
}

void Application::Update()
{
    WindowManager::Instance().Update();
}

void Application::Shutdown()
{
    WindowManager::Instance().Shutdown();
    LoggingManager::Instance().Shutdown();
}
} // namespace Magika