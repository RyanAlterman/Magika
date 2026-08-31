#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace Magika
{
class LoggingManager
{
  public:
    // Delete the copy constructor and assignment operator to prevent copying the LoggingManager
    // object
    LoggingManager(const LoggingManager&) = delete;
    LoggingManager& operator=(const LoggingManager&) = delete;

    ~LoggingManager() = default;

    static LoggingManager& Instance();

    void Initialize();
    void Shutdown();

    std::shared_ptr<spdlog::logger> GetLogger()
    {
        return m_logger;
    };

  protected:
  private:
    LoggingManager() = default;

#pragma region Member Variables
    std::shared_ptr<spdlog::logger> m_logger;
#pragma endregion
};
} // namespace Magika

// Core log macros
#define MK_LOG_TRACE(...) ::Magika::LoggingManager::Instance().GetLogger()->trace(__VA_ARGS__)
#define MK_LOG_INFO(...) ::Magika::LoggingManager::Instance().GetLogger()->info(__VA_ARGS__)
#define MK_LOG_WARN(...) ::Magika::LoggingManager::Instance().GetLogger()->warn(__VA_ARGS__)
#define MK_LOG_ERROR(...) ::Magika::LoggingManager::Instance().GetLogger()->error(__VA_ARGS__)
#define MK_LOG_CRITICAL(...) ::Magika::LoggingManager::Instance().GetLogger()->critical(__VA_ARGS__)

#ifdef MK_DEBUG
#define MK_LOG_DEBUG(...) ::Magika::LoggingManager::Instance().GetLogger()->debug(__VA_ARGS__)
#else
#define MK_LOG_DEBUG(...)
#endif