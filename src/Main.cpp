#include "Application.hpp"

#include <iostream>

int main()
{
    try
    {
        Magika::Application::Instance().Run();
    }
    // TODO: Ensure that the application cleans up resources properly in case of exceptions
    // TODO: Swap to custom logging mechanism instead of std::cerr for better control over logging
    // output
    // TODO: Consider implementing a more robust error handling strategy, possibly with custom
    // exception types for different error scenarios
    catch (const std::exception& e)
    {
        // Handle exceptions here
        std::cerr << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...)
    {
        // Handle unknown exceptions here
        std::cerr << "Unknown exception occurred." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}