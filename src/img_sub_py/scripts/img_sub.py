#!/usr/bin/env python3
import rospy
import os
from std_msgs.msg import String
from custom_msgs.msg import DetectionTracker2DArray
from vision_msgs.msg import Detection2DArray
from sensor_msgs.msg import Image
import cv2

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard something %s", data.detections)

def main():

    os.environ["ROS_MASTER_URI"]="http://192.168.1.223:11311/"
    rospy.init_node('img_sub_node')

    rospy.Subscriber('/video0/bounding_boxes', DetectionTracker2DArray, callback)

    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSException:
        pass    