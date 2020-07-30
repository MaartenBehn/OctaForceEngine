workspace "OctaForce"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OctaForce"
	location "OctaForce"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "ocpch.h"
	pchsource "OctaForce/src/ocpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"OctaForce/vendor/spdlog/include",
		"OctaForce/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OC_PLATFORM_WINDOWS",
			"OC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DEBUG"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"OctaForce/vendor/spdlog/include",
		"OctaForce/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OC_PLATFORM_WINDOWS"
		}

		links
		{
			"OctaForce"
		}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DEBUG"
		optimize "On"