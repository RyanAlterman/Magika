#include "LoggingManager.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Magika
{
LoggingManager& LoggingManager::Instance()
{
    static LoggingManager instance;
    return instance;
}

void LoggingManager::Initialize()
{
    std::vector<spdlog::sink_ptr> logSinks;
    logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logSinks.emplace_back(
        std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/Magika_Runtime.log", true));

    logSinks[0]->set_pattern("%^[%T] %n: %v%$");
    logSinks[1]->set_pattern("[%T] [%l] %n: %v");

    m_logger = std::make_shared<spdlog::logger>("MAGIKA", begin(logSinks), end(logSinks));
    spdlog::register_logger(m_logger);
    m_logger->set_level(spdlog::level::trace);
    m_logger->flush_on(spdlog::level::trace);

    MK_LOG_INFO("Logging manager initialized.");
}

void LoggingManager::Shutdown()
{
    MK_LOG_INFO("Logging manager shut down.");
}
} // namespace Magika