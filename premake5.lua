workspace "GameEngine"
	architecture "x64"

configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
	location "Game-Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
	}
	includedirs
	{
		"%{prj.location}/vendor/spdlog/include"
	}
	
	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"GE_PLATFORM_WINDOWS",
		"GE_BUILD_DLL"
	}
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/Sandbox")
	}
	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
	}
	includedirs
	{
		"Game-Engine/vendor/spdlog/include",
		"Game-Engine/src"
	}
	links
	{
		"GameEngine"
	}
	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"GE_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"