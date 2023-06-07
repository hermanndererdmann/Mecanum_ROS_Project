# OmniSeek
In dieser Bedienungsanleitung zum OmniSeek Roboter, welcher im Mobile Robotics Projekt 2, an der Fachhochschule Graubünden entwickelt wurde, finden Sie alle Informationen, um bei Ihnen zuhause das Programm über ROS zu installieren und starten. 

## Ersteller:
- Luca Bargetzi				  luca.bargetzi@stud.fhgr.ch
- Florian Büttiker			florian.buettiker@stud.fhgr.ch
- Tim Germann				    tim.germann@stud.fhgr.ch
- Yannick Kohler			  yannick.kohler@stud.fhgr.ch

## Component List
-	Microcontroller:	1x Raspberry Pi 4 4GB
-	Microcontroller:	1x STM32F401RE
-	IMU:			1x BMI088 
-	Magnetometer:	1x LIS3MDL
-	Motorcontroller	2x Sparkfun Rob 14451
-	Lidar:			1x RPLIDARA1
-	3D-Cam:		1x Xbox 360 Kinect
-	Motor:			4x YFROBOT Motor
-	3D printed chassis
-	Custom PCB

## get Rpi 4 ready

1. install Ubuntu 20.04
2. install ROS-Desktop: http://wiki.ros.org/noetic/Installation/Ubuntu
3. install libfreenect: https://aibegins.net/2020/11/22/give-your-next-robot-3d-vision-kinect-v1-with-ros-noetic/
4. clone git:
```
git clone https://github.com/hermanndererdmann/Mecanum_ROS_Project.git
```
4. create catkin workspace 
```
mkdir catkin_ws_ros
cd catkin_ws_ros
mkdir src
cd src
```
5. copy contents from git-folder Software/Rpi/ROS into catkin workspace
6. 
