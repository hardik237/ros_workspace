#include <bits/stdc++.h>
#include <stdlib.h>
#include "ros/ros.h"
#include "vision_msgs/Detection2DArray.h"
#include "vision_msgs/Detection2D.h"
#include "sensor_msgs/Image.h"

void detectionCallback(const vision_msgs::Detection2DArray::ConstPtr detection)
{
    ROS_INFO("Got detections timestamp:[%lf]", detection->header.stamp.toSec());
}

void imgCallback(const sensor_msgs::Image::ConstPtr image)
{
    ROS_INFO("Got image timestamp");
}

void segImgCallback(const sensor_msgs::Image::ConstPtr image)
{
    ROS_INFO("Got segmentation image timestamp");
}

int main(int argc, char **argv)
{
    setenv("ROS_MASTER_URI", "http://192.168.1.223:11311/", 1);
    
    ros::init(argc, argv, "img_subscriber");

    ros::NodeHandle nodeHandle;

    ros::Subscriber detectionSub0 = nodeHandle.subscribe("/video0/bounding_boxes", 100, detectionCallback);
    ros::Subscriber detectionSub1 = nodeHandle.subscribe("/video1/bounding_boxes", 100, detectionCallback);

    ros::Subscriber imgSubscriber0 = nodeHandle.subscribe("/video0", 100, imgCallback);
    ros::Subscriber imgSubscriber1 = nodeHandle.subscribe("/video1", 100, imgCallback);

    ros::Subscriber segImgSubcriber0 = nodeHandle.subscribe("/segmented_image0", 100, segImgCallback);
    ros::Subscriber segImgSubcriber1 = nodeHandle.subscribe("/segmented_image1", 100, segImgCallback);


    ros::spin();

    return 0;
}