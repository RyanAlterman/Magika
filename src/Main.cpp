#include "Application.hpp"

#include "Logging/LoggingManager.hpp"

int main()
{
    try
    {
        Magika::Application::Instance().Run();
    }
    // TODO: Ensure that the application cleans up resources properly in case of exceptions
    // TODO: Consider implementing a more robust error handling strategy, possibly with custom
    // exception types for different error scenarios
    catch (const std::exception& e)
    {
        // Handle exceptions here
        MK_LOG_ERROR("Unhandled Exception: ", e.what());
        return EXIT_FAILURE;
    }
    catch (...)
    {
        // Handle unknown exceptions here
        MK_LOG_ERROR("Unknown exception occurred.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}