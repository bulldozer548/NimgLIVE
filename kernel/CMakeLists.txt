cmake_minimum_required(VERSION 3.5)
project(nimgOS)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c sys/console.h std/types.h sys/time.c sys/time.h sys/console.c std/string.h sys/hardware.h sys/hardware.c std/string.c sys/modules.h std/stdarg.h drivers/keyboard.h drivers/keyboard.c drivers/drivers.h drivers/drivers.c init.c)
add_executable(nimgOS ${SOURCE_FILES})