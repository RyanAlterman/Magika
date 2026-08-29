#pragma once

#include <GLFW/glfw3.h>

namespace Magika
{
class WindowManager
{
  public:
    // Delete the copy constructor and assignment operator to prevent copying of the WindowManager
    // class.
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    /**
     * @brief Destroy the Window Manager object.
     *
     */
    ~WindowManager() = default;

    /**
     * @brief Gets the singleton instance of the Window Manager class.
     *
     * @return WindowManager& Reference to the singleton instance of the Window Manager class.
     */
    static WindowManager& Instance();

    /**
     * @brief Initializes the window manager.
     *
     */
    void Initialize();

    /**
     * @brief Shuts down the window manager. Releases any objects owned by the Window Manager.
     *
     */
    void Shutdown();

    /**
     * @brief Updates the window making sure buffers are setup for rendering.
     *
     */
    void Update();

    /**
     * @brief Get the Window Handle object
     *
     * @return Pointer to the GLF window handle
     */
    GLFWwindow* GetWindowHandle() const
    {
        return m_window;
    }

    /**
     * @brief Return if the window is open.
     *
     * @return true The window is open.
     * @return false The window is closed or hasn't been created.
     */
    bool IsWindowOpen() const;

  protected:
  private:
    /**
     * @brief Construct a new Window Manager object.
     *
     */
    WindowManager() = default;

#pragma region Member Variables
    GLFWwindow* m_window = nullptr;
#pragma endregion
};
} // namespace Magika