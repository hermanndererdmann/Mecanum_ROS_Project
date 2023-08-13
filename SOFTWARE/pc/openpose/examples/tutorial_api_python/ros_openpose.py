#!/usr/bin/env python3

import rospy
import cv2
import argparse
import os
from sys import platform
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from openpose import pyopenpose as op

def main():
    rospy.init_node("openpose_node")
    image_topic = rospy.get_param("~image_topic", "/openpose/keypoints")

    # Parse command-line arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--image_path", default="../../../examples/media/COCO_val2014_000000000241.jpg", help="Path to the input image.")
    args = parser.parse_args()

    # Custom Params
    params = dict()
    params["model_folder"] = "../../../models/"
    params["face"] = True
    params["hand"] = True

    # Starting OpenPose
    opWrapper = op.WrapperPython()
    opWrapper.configure(params)
    opWrapper.start()

    # Load the image from the specified path
    image_path = os.path.abspath(args.image_path)
    imageToProcess = cv2.imread(image_path)

    # Process Image
    datum = op.Datum()
    datum.cvInputData = imageToProcess
    opWrapper.emplaceAndPop(op.VectorDatum([datum]))

    # Convert the image with keypoints to a ROS Image message
    bridge = CvBridge()
    image_msg = bridge.cv2_to_imgmsg(datum.cvOutputData, encoding="bgr8")

    # Publish the image with keypoints
    pub = rospy.Publisher(image_topic, Image, queue_size=10)
    rate = rospy.Rate(10)  # Publish rate (10 Hz)
    while not rospy.is_shutdown():
        pub.publish(image_msg)
        rate.sleep()

if __name__ == '__main__':
    main()

