workspace "lc98"
	configurations { "ReleaseIII", "DebugIII", "ReleaseVC", "DebugVC" }
	location "build"
   
	files { "src/*.*" }
   
	includedirs { "src" }
	includedirs { os.getenv("RWSDK33") }
   
project "lc98"
	kind "SharedLib"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	targetextension ".dll"
	characterset ("MBCS")

	filter "configurations:DebugIII"
		defines { "DEBUG", "III" }
		symbols "On"
		debugdir "C:/Users/aap/games/gta3"
		debugcommand "C:/Users/aap/games/gta3/gta3.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gta3\\plugins\\\""

	filter "configurations:ReleaseIII"
		defines { "NDEBUG", "III" }
		optimize "On"
		flags { "StaticRuntime" }
		debugdir "C:/Users/aap/games/gta3"
		debugcommand "C:/Users/aap/games/gta3/gta3.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gta3\\plugins\\\""

	filter "configurations:DebugVC"
		defines { "DEBUG", "VC" }
		symbols "On"
		debugdir "C:/Users/aap/games/gtavc"
		debugcommand "C:/Users/aap/games/gtavc/gta_vc.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gtavc\\dlls\\vc84.dll\""

	filter "configurations:ReleaseVC"
		defines { "NDEBUG", "VC" }
		optimize "On"
		flags { "StaticRuntime" }
		debugdir "C:/Users/aap/games/gtavc"
		debugcommand "C:/Users/aap/games/gtavc/gta_vc.exe"
		postbuildcommands "copy /y \"$(TargetPath)\" \"C:\\Users\\aap\\games\\gtavc\\dlls\\vc84.dll\""
