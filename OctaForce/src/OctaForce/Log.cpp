#include "ocpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace OctaForce 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_CLientLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("OctaForec");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CLientLogger = spdlog::stdout_color_mt("App");
		s_CLientLogger->set_level(spdlog::level::trace);
	}
}
