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


#define BIT(x) (1 << x)