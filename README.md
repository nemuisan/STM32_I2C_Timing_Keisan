I2C Timing Register Calculator for STM32
====================================
Calculate I2C Timing Register Value for STM32.  
kanari "yakketsu" desu  

Functions
------
- Usage  
 1.Input Kernel Clock left form(in MHZ, 0~300).  
 2.Input I2C Clock(in kHz, 100,400 and 1000 only) right form.  
 3.Push "Calculate!"  
 4.Copy calculated value.  

!calculate value 0x0 is "error"!  

Build
------
Use Microsoft Visual Studio 2017~  

License
-------
- Main program  
BSD 3-Clause license,  
See detail below URL.  
http://bcaweb.bai.ne.jp/44unk/inachang/Copyright.txt  

- i2c_timing_utility.c and i2c_timing_utility.h  
 Copyright (c) 2020 STMicroelectronics.  
 All rights reserved.  
 This software component is licensed by ST under BSD 3-Clause license,  
 the "License"; You may not use this file except in compliance with the  
 License. You may obtain a copy of the License at:  
 opensource.org/licenses/BSD-3-Clause  