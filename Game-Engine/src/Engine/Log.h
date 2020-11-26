#pragma once
#include <gepch.h>
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
namespace ge {

	class GAMEENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
#define GE_CORE_TRACE(...)  ::ge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)	::ge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)	::ge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)	::ge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)  ::ge::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define GE_TRACE(...)		::ge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)		::ge::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)		::ge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)		::ge::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...)		::ge::Log::GetClientLogger()->fatal(__VA_ARGS__)
