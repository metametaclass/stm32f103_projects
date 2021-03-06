# stm32f103 projects

libopencm3-based software projects for generic [stm32f103c8t6 board](http://www.ebay.com/itm/1pcs-STM32F103C8T6-ARM-STM32-Minimum-System-Development-Board-Module-Arduino-/201414966215)



# Build libopencm3 and projects on Windows:


* Clone projects repo:

```
git clone https://github.com/metametaclass/stm32f103_projects
```


* init libopencm3 submodule:

```
git submodule init
git submodule update
```
 
* download gcc-arm embedded toolchain: https://launchpad.net/gcc-arm-embedded

  (e.g.  https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q2-update/+download/gcc-arm-none-eabi-5_4-2016q2-20160622-win32.zip)

* unpack gcc-arm-XXXX.zip somewhere

* download and install MSYS: http://www.mingw.org/wiki/MSYS http://downloads.sourceforge.net/mingw/MSYS-1.0.11.exe

* download and install python 2.7:  https://www.python.org/ftp/python/2.7/python-2.7.msi (needed for file generation in libopencm3)


* run MSYS with PATH to python and gcc:

* create and run script run_msys_gcc_arm.cmd in MSYS folder (where msys.bat is located):

```
rem change path to installed python and gcc-arm 'bin' folder
set PATH=%PATH%;D:\Programm\Python27;D:\Programm\gcc-arm\bin
call %~dp0msys.bat
```


* build libopencm3:


In opened MSYS shell `cd` to libopencm3 folder and run `make`:

```
cd /c/work/stm32f103_projects/libopencm3/
make
```


* build projects:
`cd` to any project folder and run `make`:
    
```
cd ../projects/blink
make
```


# Programming on Linux with STLinkV2:

https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki/Programming-an-STM32F103XXX-with-a-generic-%22ST-Link-V2%22-programmer-from-Linux


* Wiring

stlink -> board programming pins

```
8 Vcc(3.3) -> 3.3
2 SWDIO    -> SWDIO  (PA13, pin 34)
6 SWCLK    -> SWDCLK (PA14, pin 37)
4 Ground   -> GND
```

* interactive programming:
run openocd

```
openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f1x_stlink.cfg
```

* run in separate terminal:
```
telnet localhost 4444
reset halt; flash write_image erase binary.elf; reset run

```



* automatic programming from script:

```
openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg \
        -f /usr/share/openocd/scripts/target/stm32f1x_stlink.cfg \
        -c init -c "reset halt; flash write_image erase binary.elf; reset run; shutdown"
```

`init` command is imporant, all other commands works only after init call

