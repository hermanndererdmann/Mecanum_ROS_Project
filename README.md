# OmniSeek
![robot](https://github.com/hermanndererdmann/Mecanum_ROS_Project/assets/64459587/38fc09db-1e92-4c84-a349-d115479ea19b)
In this manual for the OmniSeek robot, which was developed in the Mobile Robotics Project 2, at the University of Applied Sciences Grisons, you will find all the information you need to install and start the program at your home via ROS.

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
6. create catkin workspace 
```
mkdir catkin_ws_ros
cd catkin_ws_ros
mkdir src
cd src
```
7. Symlink contents from git-folder /Mecanum_ROS_Project/Software/Rpi/ROS into catkin_ws_ros/src
```
> ln -s ~/.../Mecanum_ROS_Project/Software/Rpi/ROS/ 
```
8. Build the package with: (while in the catkin_ws_ros folder)
```
cd ..
catkin_make
```
9. Re-source your workspace setup:
```
source devel/setup.bash
```
10. Run roscore in a seperate console
```
roscore
```
11. Launch the node with
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
### Build Docker Image
This step can be skipped if the image is downloaded.

Navigate to the cloned repository and run

```
docker build -t ros-openpose-docker .
```
after this the image is build and saved on the drive.

### Run Docker Image
```
xhost +local:root; docker run -ti --rm  --gpus all --net=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw ros-openpose-docker
```

With each start of the container, the hostname & IP of the ROS slave have to be added to the ects/hosts file with `nano`. Both IP addresses should be static.

In my example this is:
```
10.0.106.30 rosberry
```
After this we can start the `roscore`.


### Starting Openpose
To start Openpose or other services in the container we need to open a new terminal. To get into the running Docker Container use:
```
docker exec -it <YOUR-BUILT-CONTAINER-NAME> bash
```

Navigate to `/openpose/build/examples/tutorial_api_python` and start `ros_openpose.py`



