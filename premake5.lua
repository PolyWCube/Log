workspace "CustomLog"
	architecture "x64"
	configurations {
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CustomLog"
	location "CustomLog"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.cpp"
	}
	
	includedirs {
		"%{prj.name}/src"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"CUSTOM_PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines "CUSTOM_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"
		linkoptions { "/NODEFAULTLIB:LIBCMT" }

	filter "configurations:Release"
		defines "CUSTOM_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		symbols "on"
		optimize "on"
		linkoptions { "/NODEFAULTLIB:LIBCMT" }