# rosserial_stm32

## Note
This is a part of [rosserial](https://github.com/ros-drivers/rosserial) repository to communicate with ROS system through a USART for STM32 embedded system.

## Limitation
The original code is focused on STM32F3xx, 4xx, and 7xx series and it uses the [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) or [STM32CubeMX HAL](http://www.st.com/en/development-tools/stm32cubemx.html).  
If you use the package for other series, please edit [the following line](https://github.com/yoneken/rosserial_stm32/blob/master/src/ros_lib/STM32Hardware.h#L38) on src/ros_lib/STM32Hardware.h .  

## Generate code
$ cd _target_workspace_ (It should contain Inc and Src directories).  
$ rosrun rosserial_stm32 make_libraries.py .  
**Never forget to change the project type to _cpp project_ in STM32CubeIDE or SW4STM32!!**  
**For STM32CubeIDE users:** [You have to add /Inc directory as a "Source Location" in the project properties(C/C++ General > Paths and Symbols > Source Location).](https://github.com/yoneken/rosserial_stm32/issues/10#issuecomment-573997253)  

## Examples
See [src/ros_lib/examples](https://github.com/yoneken/rosserial_stm32/tree/master/src/ros_lib/examples)  

## Share your implementation based on this repo here
_Make sure your code is working before adding your repo here ;)_

* [Hello World example](https://dev.azure.com/stevenfarthenDev/_git/HelloWorld) is a copy of [ROSserial chatter](https://github.com/yoneken/rosserial_stm32/tree/master/src/ros_lib/examples/chatter) but reconfigured to be directly used by [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html).

* [LEDs control through publishers example](https://stevenfarthenDev@dev.azure.com/stevenfarthenDev/BlinkingLED/_git/BlinkingLED)Send UART rosserial commands controlling LED blinking time. Configured for ST NUCLEO-F401RE.

* [A simple temperature and pressure example](https://stevenfarthenDev@dev.azure.com/stevenfarthenDev/X_NUCLEO_IKS01A2_Shield/_git/X_NUCLEO_IKS01A2_Shield) Gather temperature & pressure data and publish them to ROS python client using ST [X-NUCLEO-IKS01A2](https://www.st.com/content/st_com/en/products/ecosystems/stm32-open-development-environment/stm32-nucleo-expansion-boards/stm32-ode-sense-hw/x-nucleo-iks01a2.html) shield.

* [Motion and environment multi-publisher sensing example](https://stevenfarthenDev@dev.azure.com/stevenfarthenDev/ROS-X-NUCLEO-IKS01A2/_git/ROS-X-NUCLEO-IKS01A2)
This project is a multi-nodes publishers example with both environment (Pressure, humidity, temperature) and motion (magnetic, accelerometer, 6DOF inertia) sensing. It has been tested on [[NUCLEO-F401RE](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f401re.html) top up with [X-NUCLEO-IKS01A2](https://www.st.com/content/st_com/en/products/ecosystems/stm32-open-development-environment/stm32-nucleo-expansion-boards/stm32-ode-sense-hw/x-nucleo-iks01a2.html) shield. It also shows how a C++ wrapper could be used to be integrated into a C demonstration code.

* [fdila's repo, working with STM32CubeIDE and stm32f7 based board, CURRENTLY NOT MAINTAINED](https://github.com/fdila/rosserial_stm32f7)

## On a Windows machine with virtual machine
### Note

- Make sure Hyper-V is correctly disabled.

### Required softwares
- VirtualBox
- Vagrant

### Run

1. Generate headers for STM32

_Terminal 1_
```
> cd *rosserial_stm32 dir*
> vagrant up
> vagrant ssh

$ cd rosserial_stm32
$ docker-compose up prepare
```

Then, a sample project is generated on _rosserial_stm32/src/ros_lib/examples/chatter/_ .

2. Build code with STM32CubeIDE on **Windows**

- Open new workspace
- Import the project as a ac6 System Workbench for STM32 project
- Open *.ioc file with Device Configuration Tool
- Generate codes with the tool
- Change project type to C++ project on Eclipse
- **Only STM32CubeIDE users**: Add /Inc directory to "Source Location" on project properties (C/C++ General > Paths and Symbols > Source Location)
- Build

3. Launch rosseral server

_Terminal 1_
```
$ docker-compose up srv
```

4. Flash binary on STM32 and start a demo

_Terminal 2_
```
> cd *rosserial_stm32 dir*
> vagrant ssh

$ cd rosserial_stm32
$ docker-compose up client
```
5. Stop and remove all containers

_Terminal 2_
```
[Ctrl+C]
$ exit
```

_Terminal 1_
```
[Ctrl+C]
$ docker stop $(docker ps -q)
$ docker rm $(docker ps -q -a)
$ exit

> vagrant halt
```
