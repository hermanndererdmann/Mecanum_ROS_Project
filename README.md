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

## 1. get Rpi 4 ready
Everything under this Topic should be done directly on the Raspberry Pi.
1. install Ubuntu 20.04
2. install ROS-Desktop: http://wiki.ros.org/noetic/Installation/Ubuntu
3. setup ros master on rpi according to http://wiki.ros.org/ROS/Tutorials/MultipleMachines
4. install libfreenect: https://aibegins.net/2020/11/22/give-your-next-robot-3d-vision-kinect-v1-with-ros-noetic/
5. clone git:
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
8. Run roscore in a seperate console
```
roscore
```
9. Launch the node with
```
roslaunch ros_package_template ros_package_template.launch
```

### start rosserial 
1. Find the right port
```
dmesg | grep tty
```
2. enable port (choose right port: ACMx)
```
sudo chmod 666 /dev/ttyACM0
```
3. Start the serial_node.py (choose right port: ACMx)
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
### start teleop bridge
```
rosrun teleop_bridge joy_twist_bridge.py
```
### start ps3joy (~catkin_ws/src/ps3joy/src/joystick_drivers)
```
roslaunch ps3joy ps3.launch
```
### start freenect
```
roslaunch freenect_launch freenect.launch
```


## 2. get the STM32 ready
1. open the Project /Mecanum_ROS_Project/Software/STM/ROS/
2. run the Project
3. disconnect the cable from the pc
4. plug the STM32 to the Raspberry PI

## 3. get the pc ready
The Setup for the video analysis on the pc:
1. Install Ubuntu 20.04 (dualboot or directly)
2. install ROS-Desktop-Full: http://wiki.ros.org/noetic/Installation/Ubuntu
3. setup ros slave on pc according to http://wiki.ros.org/ROS/Tutorials/MultipleMachines
4. git clone https://github.com/hermanndererdmann/Mecanum_ROS_Project.git

5. create catkin workspace 
```
mkdir catkin_ws_ros
cd catkin_ws_ros
mkdir src
cd src
```
6. Symlink contents from git-folder /Mecanum_ROS_Project/Software/Rpi/ROS into catkin_ws_ros/src
```
> ln -s ~/.../Mecanum_ROS_Project/Software/PC/ROS/ 
```
7. Build the package with: (while in the catkin_ws_ros folder)
```
cd ..
catkin_make
```
8. Re-source your workspace setup:
```
source devel/setup.bash
```
9. Openpose
```
mkdir openpose
ln -s ~/.../Mecanum_ROS_Project/Software/PC/openpose/ 
```
10. compile and make according to https://github.com/CMU-Perceptual-Computing-Lab/openpose/blob/master/doc/installation/0_index.md#cmake-configuration

12.  start openpose script video_feedback.py
```
cd examples/tutorial_api_python/
python3 video_feedback.py
```


