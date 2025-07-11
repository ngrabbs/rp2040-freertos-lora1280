cmake_minimum_required(VERSION 3.13)

# Name project
set(ProjectName rp2040-freertos-sx1280)

# Set any variables required for importing libraries
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

# Import libraries
include(pico_sdk_import.cmake)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# Define project
project(${ProjectName} C CXX ASM)

# Initialize Pico SDK
pico_sdk_init()

# Define executable
add_executable(${ProjectName}
    src/main.cpp
    src/lora_task.cpp
    src/lora1280.cpp
    src/SX1280.cpp
)

# Enable USB serial (set to 1 to enable)
pico_enable_stdio_usb(${ProjectName} 1)
pico_enable_stdio_uart(${ProjectName} 0)

# Add include paths
target_include_directories(${ProjectName} PRIVATE src)

# Link libraries
target_link_libraries(${ProjectName} pico_stdlib hardware_spi FreeRTOS-Kernel-Heap4)

# Optional: Disable picotool if not needed
set(PICO_NO_FLASH 0)
set(PICO_COPY_TO_RAM 0)

# Create UF2, bin, and other outputs
pico_add_extra_outputs(${ProjectName})
