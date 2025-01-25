# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Animacoes C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Animacoes main.c )

pico_set_program_name(Animacoes "Animacoes")
pico_set_program_version(Animacoes "0.1")


target_include_directories(Animacoes PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/Modulos
)

pico_generate_pio_header(Animacoes ${CMAKE_CURRENT_LIST_DIR}/Modulos/pio_matrix.pio)

target_sources(Animacoes PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/Modulos/keypad.c
  ${CMAKE_CURRENT_LIST_DIR}/Modulos/led.c
  ${CMAKE_CURRENT_LIST_DIR}/Modulos/buzzer.c
  ${CMAKE_CURRENT_LIST_DIR}/animacoes.c
)

pico_enable_stdio_uart(Animacoes 1)
pico_enable_stdio_usb(Animacoes 0)

# Add the standard library to the build
target_link_libraries(Animacoes
  pico_stdlib
  hardware_pwm
  hardware_pio
  hardware_clocks
)
pico_add_extra_outputs(Animacoes)

