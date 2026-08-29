#pragma once

namespace Magika
{
/**
 * @brief Root application class that controls the lifetime of
 * the application and manages the main loop.
 *
 */
class Application
{
  public:
    // Delete the copy constructor and assignment operator to prevent copying of the Application
    // class.
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    /**
     * @brief Destroy the Application object.
     *
     */
    ~Application() = default;

    /**
     * @brief Gets the singleton instance of the Application class.
     *
     * @return Application& Reference to the singleton instance of the Application class.
     */
    static Application& Instance();

    /**
     * @brief Runs the application.
     *
     */
    void Run();

  protected:
  private:
    /**
     * @brief Constructs an instance of the Application class.
     */
    Application() = default;

    /**
     * @brief Initializes the application.
     */
    void Initialize();

    /**
     * @brief Updates the application state.
     */
    void Update();

    /**
     * @brief Shuts down the application.
     */
    void Shutdown();
};
} // namespace Magika