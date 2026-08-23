#include "Application.hpp"

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
    while (false) // Main loop
    {
        Update();
        // Render(); // You can add a Render function if needed
    }

    Shutdown();
}

void Application::Initialize()
{
    // Initialization code here
}

void Application::Update()
{
    // Update application state here
}

void Application::Shutdown()
{
    // Cleanup code here
}
} // namespace Magika