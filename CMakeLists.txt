cmake_minimum_required(VERSION 3.10)
project(pinetime VERSION 0.10.1 LANGUAGES C CXX ASM)

set(NRF_TARGET "nrf52")

if (NOT ARM_NONE_EABI_TOOLCHAIN_PATH)
  message(FATAL_ERROR "The path to the toolchain (arm-none-eabi) must be specified on the command line (add -DARM_NONE_EABI_TOOLCHAIN_PATH=<path>")
endif ()

if (NOT NRF5_SDK_PATH)
  message(FATAL_ERROR "The path to the NRF52 SDK must be specified on the command line (add -DNRF5_SDK_PATH=<path>")
endif ()

if(NOT USE_JLINK AND NOT USE_GDB_CLIENT AND NOT USE_OPENOCD)
  set(USE_JLINK true)
endif()

if(USE_JLINK)
  if (NOT NRFJPROG)
    message(FATAL_ERROR "the path to the tool nrfjprog must be specified on the command line (add -DNRFJPROG=<path>")
  endif ()
endif()

if(USE_GDB_CLIENT)
  if(NOT GDB_CLIENT_BIN_PATH)
    set(GDB_CLIENT_BIN_PATH "arm-none-eabi-gdb")
  endif()

  if(NOT GDB_CLIENT_TARGET_REMOTE)
    message(FATAL_ERROR "The GDB target must be specified (add -DGDB_CLIENT_TARGET_REMOTE=<target>")
  endif()
endif()

if(USE_OPENOCD)
  if(NOT OPENOCD_BIN_PATH)
    set(OPENOCD_BIN_PATH "openocd")
  endif()
endif()

if(DEFINED USE_DEBUG_PINS AND USE_DEBUG_PINS)
  add_definitions(-DUSE_DEBUG_PINS)
endif()

message("BUILD CONFIGURATION")
message("-------------------")
message("    * Version : " ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
message("    * Toolchain : " ${ARM_NONE_EABI_TOOLCHAIN_PATH})
message("    * NRF52 SDK : " ${NRF5_SDK_PATH})
set(PROGRAMMER "???")
if(USE_JLINK)
  message("    * Programmer/debugger : JLINK")
  message("    * NrfJprog : " ${NRFJPROG})
elseif(USE_GDB_CLIENT)
  message("    * Programmer/debugger : GDB Client")
  message("    * GDB Client path : " ${GDB_CLIENT_BIN_PATH})
  message("    * GDB Target : " ${GDB_CLIENT_TARGET_REMOTE})
elseif(USE_OPENOCD)
  message("    * Programmer/debugger : OpenOCD Client")
endif()
if(USE_DEBUG_PINS)
  message("    * Debug pins : Enabled")
else()
  message("    * Debug pins : Disabled")
endif()

set(VERSION_EDIT_WARNING "// Do not edit this file, it is automatically generated by CMAKE!")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/Version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/Version.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docker/post_build.sh.in ${CMAKE_CURRENT_BINARY_DIR}/post_build.sh)


add_subdirectory(src)

