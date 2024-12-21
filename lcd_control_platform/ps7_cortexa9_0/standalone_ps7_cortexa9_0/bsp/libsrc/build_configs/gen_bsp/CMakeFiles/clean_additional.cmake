# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\prana\\Documents\\Projects\\FPGA-Soc\\lcd_control_ps\\lcd_control_platform\\ps7_cortexa9_0\\standalone_ps7_cortexa9_0\\bsp\\include\\sleep.h"
  "C:\\Users\\prana\\Documents\\Projects\\FPGA-Soc\\lcd_control_ps\\lcd_control_platform\\ps7_cortexa9_0\\standalone_ps7_cortexa9_0\\bsp\\include\\xiltimer.h"
  "C:\\Users\\prana\\Documents\\Projects\\FPGA-Soc\\lcd_control_ps\\lcd_control_platform\\ps7_cortexa9_0\\standalone_ps7_cortexa9_0\\bsp\\include\\xtimer_config.h"
  "C:\\Users\\prana\\Documents\\Projects\\FPGA-Soc\\lcd_control_ps\\lcd_control_platform\\ps7_cortexa9_0\\standalone_ps7_cortexa9_0\\bsp\\lib\\libxiltimer.a"
  )
endif()
