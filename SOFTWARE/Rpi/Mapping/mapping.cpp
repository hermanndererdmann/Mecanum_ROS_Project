/*--------------------------------------------------
Mobiles Robotikprojekt 2
---------------------------------------------------*/
#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <sensor_msgs/LaserScan.h>
#include <fstream>

void saveMapAsPGM(const nav_msgs::OccupancyGrid& map)
{
  std::ofstream file("map.pgm");
  if (!file.is_open())
  {
    ROS_ERROR("Failed to open the file for saving the map.");
    return;
  }

  // PGM file header
  file << "P2" << std::endl;
  file << map.info.width << " " << map.info.height << std::endl;
  file << "255" << std::endl;

  // PGM image data
  for (const auto& cell : map.data)
  {
    if (cell == 0)
    {
      // Free space (white color)
      file << "255 ";
    }
    else if (cell == 100)
    {
      // Occupied space (black color)
      file << "0 ";
    }
    else
    {
      // Unknown space (gray color)
      file << "125 ";
    }
  }

  file.close();

  ROS_INFO("Map saved as map.pgm");
}

void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  ROS_INFO("Received map data");

  saveMapAsPGM(*msg);
}

void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
  // Access lidar data from the 'scan' message
  std::vector<float> ranges = scan->ranges;
  // Process the lidar data as needed
  // ...
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "mapping_and_lidar_node");
  ros::NodeHandle nh;

  // Subscribe to the map topic
  ros::Subscriber map_sub = nh.subscribe("/map", 1, mapCallback);

  // Subscribe to the lidar topic
  ros::Subscriber lidar_sub = nh.subscribe("/lidar_topic", 1, lidarCallback);

  ros::spin();

  return 0;
}

