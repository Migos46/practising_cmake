cmake_minimum_required(VERSION 3.15)

project(vsCode VERSION 0.0.1)

add_library(vscode_compile_flags INTERFACE)
target_compile_features(vscode_compile_flags INTERFACE cxx_std_11)
# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# If user selects debugging build, build with debug flags
option(DEBUG_BUILD "If user wants add -g flag to build app" OFF)
# Configuring the project with or without verbose
option(USE_LOG "Change the application to be more verbose" OFF)

target_compile_options(vscode_compile_flags INTERFACE
    "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
    "$<${msvc_cxx}:-W3>"
)
# $<BOOL:string>
# Converts string to 0 or 1. Evaluates to 0 if any of the following is true:
# string is a case-insensitive equal of 0, FALSE, OFF, N, NO, IGNORE, or NOTFOUND
# more in cmake manual. Otherwise evaluates to 1
target_compile_options(vscode_compile_flags INTERFACE
    "$<$<BOOL:${DEBUG_BUILD}>:-g>"
)

add_executable(vsCode hello-world-vsCode.cpp)

target_link_libraries(vsCode PUBLIC vscode_compile_flags)

# Add a macro like USE_LOG to activate prints and have the posibility to redirect the output either to a file or in the terminal
# Second, if USE_LOG is ON, lest define "USE_LOG"
if (USE_LOG)
    target_compile_definitions(vsCode PRIVATE "USE_LOG")
endif()