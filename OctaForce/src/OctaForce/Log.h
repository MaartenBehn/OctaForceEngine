#pragma once

#include "OctaForce/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace OctaForce
{
	class OC_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CLientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_CLientLogger;

	};
}

// Core log macros
#define OC_CORE_TRACE(...) ::OctaForce::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OC_CORE_INFO(...) ::OctaForce::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OC_CORE_WARN(...) ::OctaForce::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OC_CORE_ERROR(...) ::OctaForce::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OC_CORE_FATAL(...) ::OctaForce::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define OC_TRACE(...) ::OctaForce::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OC_INFO(...) ::OctaForce::Log::GetClientLogger()->info(__VA_ARGS__)
#define OC_WARN(...) ::OctaForce::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OC_ERROR(...) ::OctaForce::Log::GetClientLogger()->error(__VA_ARGS__)
#define OC_FATAL(...) ::OctaForce::Log::GetClientLogger()->fatal(__VA_ARGS__)