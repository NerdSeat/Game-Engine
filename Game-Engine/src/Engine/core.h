#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GAMEENGINE_API _declspec(dllexport)
	#else
		#define GAMEENGINE_API _declspec(dllimport)
	#endif // GE_BUILD_DLL
#else
	#error This game engine is only supported on Windows
#endif

#ifdef GE_ENABLE_ASSERTS
#define GE_ASSERTS(x,...){if(!x){GE_ERROR("Assertion failed:{0}",__VA_ARGS__);__debugbreak();}}
#define GE_CORE_ASSERTS(x,...){if(!x){GE_CORE_ERROR("Assertion failed:{0}",__VA_ARGS__);__debugbreak();}}

#else
#define GE_ASSERT(x,...)
#define GE_CORE_ASSERT(x,...)
#endif // GE_ENABLE_ASSERTS


#define BIT(x) (1 << x)