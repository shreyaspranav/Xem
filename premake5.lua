workspace "XemTest"
    architecture "x86_64"
    configurations { "Debug", "Release" }

project "XemTest"
    location "test/"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.h", "**.c" }

    includedirs { "Xem/" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"