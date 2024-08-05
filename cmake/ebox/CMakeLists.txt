cmake_minimum_required(VERSION 3.22)

project(eBox)
add_library(ebox INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM CXX)

target_compile_definitions(ebox INTERFACE
    # For ebox
	STM32F10X_MD
    STM32F103xE
    # For startup in CMSIS 5
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(ebox INTERFACE
    # Startup from CMSIS 5
    ../../Drivers/startup/Include
    # Source Code
    ../../Core/Inc
    # eBox
    ../../Drivers/ebox/core
    ../../Drivers/ebox/hardware/cortex-m3
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals
    ../../Drivers/eBox/interface
    ../../Drivers/ebox/interface/spi
    ../../Drivers/ebox/interface/i2c
    ../../Drivers/ebox/interface/event
    ../../Drivers/mcuLib/stm32f10x/libraries/CMSIS/CM3/CoreSupport
    ../../Drivers/mcuLib/stm32f10x/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/inc
    # Component
    ../../Drivers/ebox/component
    ../../Drivers/ebox/component/edriver
    ../../Drivers/ebox/component/apps
    ../../Drivers/ebox/component/Ethernet3
    ../../Drivers/ebox/component/Ethernet3/utility
)

target_sources(ebox INTERFACE
    # ebox default startup, There is no workable linker.ld
    # ../../Drivers/mcuLib/stm32f10x/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.s
    # ../../Drivers/mcuLib/stm32f10x/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
    # CMSIS 5 startup
    ../../Drivers/startup/startup_stm32f102xb.s
    ../../Drivers/startup/system_stm32f1xx.c
    ../../Core/Src/main.cpp
    ../../Core/Src/sysmem.c
    ../../Core/Src/bsp_ebox.cpp
    ../../Drivers/ebox/core/ebox_init.cpp
    ../../Drivers/ebox/core/ebox_mem.c
    ../../Drivers/ebox/core/Stream.cpp
    ../../Drivers/ebox/core/Dstring.cpp
    ../../Drivers/ebox/core/IPAddress.cpp
    ../../Drivers/ebox/core/Stream.cpp
    ../../Drivers/ebox/core/WString.cpp
    ../../Drivers/ebox/core/big_little.c
    ../../Drivers/ebox/core/crc.c
    ../../Drivers/ebox/core/ebox_core.cpp
    ../../Drivers/ebox/core/ebox_init.cpp
    ../../Drivers/ebox/core/ebox_math.cpp
    ../../Drivers/ebox/core/ebox_mem.c
    ../../Drivers/ebox/core/fifo.c
    ../../Drivers/ebox/core/itoa.c
    ../../Drivers/ebox/core/list_c.c
    ../../Drivers/ebox/core/myprintf.c
    ../../Drivers/ebox/core/new.cpp
    ../../Drivers/ebox/core/print.cpp
    ../../Drivers/ebox/core/ringbuf.cpp
    ../../Drivers/ebox/core/sort.cpp
    ../../Drivers/ebox/hardware/cortex-m3/object.cpp
    ../../Drivers/ebox/hardware/cortex-m3/nvic.cpp
    ../../Drivers/ebox/hardware/cortex-m3/rcc.cpp
    ../../Drivers/ebox/hardware/cortex-m3/dma.cpp
    ../../Drivers/ebox/hardware/cortex-m3/ebox_it.cpp
    ../../Drivers/ebox/hardware/cortex-m3/mcu.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_rtc.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_gpio.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_uart.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_pwm.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_mcu_spi.cpp
    ../../Drivers/ebox/hardware/cortex-m3/Peripherals/ebox_mcu_i2c.cpp
    ../../Drivers/ebox/interface/spi/soft_spi.cpp
    ../../Drivers/ebox/interface/i2c/i2c.cpp
    ../../Drivers/ebox/interface/i2c/soft_i2c.cpp
    ../../Drivers/ebox/interface/event/EventVar.cpp
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rtc.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c
    ../../Drivers/mcuLib/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/src/misc.c
    # Component
    ../../Drivers/ebox/component/edriver/colorled.cpp
    ../../Drivers/ebox/component/apps/color_convert.cpp
    ../../Drivers/ebox/component/Ethernet3/utility/w5500.cpp
)

target_link_directories(ebox INTERFACE
)

target_link_libraries(ebox INTERFACE
)

if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()
if(CMAKE_CXX_STANDARD LESS 11)
    message(ERROR "Generated code requires CXX11 or higher")
endif()
