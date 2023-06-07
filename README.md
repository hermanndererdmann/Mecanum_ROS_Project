# OmniSeek
In this manual for the OmniSeek robot, which was developed in the Mobile Robotics Project 2, at the University of Applied Sciences Grisogns, you will find all the information you need to install and start the program at your home via ROS.

## Creators:
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
5. Symlink contents from git-folder /Mecanum_ROS_Project/Software/Rpi/ROS into catkin_ws_ros/src
```
> ln -s ~/.../Mecanum_ROS_Project/Software/Rpi/ROS/ 
```
6. Build the package with: (while in the catkin_ws_ros folder)
```
cd ..
catkin_make
```
7. Re-source your workspace setup:
```
source devel/setup.bash
```
8. Launch the node with
```
roslaunch ros_package_template ros_package_template.launch
```

## get the STM32 ready
1. Open the Project /Mecanum_ROS_Project/Software/Rpi/ROS/

