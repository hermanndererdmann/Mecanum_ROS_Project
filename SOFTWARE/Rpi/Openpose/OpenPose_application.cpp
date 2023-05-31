/*--------------------------------------------------
Mobiles Robotikprojekt 2
---------------------------------------------------*/

// Third-party dependencies
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

// OpenPose dependencies
#include <openpose/headers.hpp>

// Custom OpenPose flags
// Producer
DEFINE_string(image_path, "", "Process frames from webcam. Overrides the image_path flag.");

// Display
DEFINE_bool(no_display, false, "Enable to disable the visual display.");

// ROS subscriber callback function for processing images
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        // Convert ROS image message to OpenCV image
        cv_bridge::CvImagePtr cvImagePtr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        cv::Mat cvFrame = cvImagePtr->image;

        // Process and display image
        const op::Matrix imageToProcess = OP_CV2OPCONSTMAT(cvFrame);
        auto datumProcessed = opWrapper.emplaceAndPop(imageToProcess);
        if (datumProcessed != nullptr)
        {
            printKeypoints(datumProcessed);
            if (!FLAGS_no_display)
            {
                display(datumProcessed);
            }
        }
        else
        {
            op::opLog("Image could not be processed.", op::Priority::High);
        }
    }
    catch (const std::exception& e)
    {
        op::error(e.what(), __LINE__, __FUNCTION__, __FILE__);
    }
}

// This worker will just read and return all the jpg files in a directory
void display(const std::shared_ptr<std::vector<std::shared_ptr<op::Datum>>>& datumsPtr)
{
    try
    {
        // datum.poseKeypoints: Array<float> with the estimated pose
        if (datumsPtr != nullptr && !datumsPtr->empty())
        {
            // Display image
            const cv::Mat cvMat = OP_OP2CVCONSTMAT(datumsPtr->at(0)->cvOutputData);
            if (!cvMat.empty())
            {
                // Draw bounding boxes
                const auto& poseKeypoints = datumsPtr->at(0)->poseKeypoints;
                const int numPeople = poseKeypoints.getSize(0);
                const int numBodyParts = poseKeypoints.getSize(1);
                for (int person = 0; person < numPeople; ++person)
                {
                    // Calculate bounding box coordinates
                    float minX = std::numeric_limits<float>::max();
                    float minY = std::numeric_limits<float>::max();
                    float maxX = std::numeric_limits<float>::lowest();
                    float maxY = std::numeric_limits<float>::lowest();
                    for (int bodyPart = 0; bodyPart < numBodyParts; ++bodyPart)
                    {
                        const float x = poseKeypoints[{person, bodyPart, 0}];
                        const float y = poseKeypoints[{person, bodyPart, 1}];
                        if (x != 0.0f && y != 0.0f)
                        {
                            minX = std::min(minX, x);
                            minY = std::min(minY, y);
                            maxX = std::max(maxX, x);
                            maxY = std::max(maxY, y);
                        }
                    }
                    // Add margin
                    minX -= 50;
                    minY -= 50;
                    maxX += 50;
                    maxY += 50;

                    // Draw bounding box rectangle
                    cv::rectangle(cvMat, cv::Point(minX, minY), cv::Point(maxX, maxY), cv::Scalar(0, 255, 0), 2);
                }

                // Draw text on the image indicating the number of people detected
                cv::putText(cvMat, "People detected: " + std::to_string(datumsPtr->at(0)->poseKeypoints.getSize(0)), cv::Point(10, 20), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 0, 255), 2);
                cv::imshow("Videofeed Detection", cvMat);
                cv::waitKey(1);
            }
            else
            {
                op::opLog("Empty cv::Mat as output.", op::Priority::High, __LINE__, __FUNCTION__, __FILE__);
            }
        }
        else
        {
            op::opLog("Nullptr or empty datumsPtr found.", op::Priority::High);
        }
    }
    catch (const std::exception& e)
    {
        op::error(e.what(), __LINE__, __FUNCTION__, __FILE__);
    }
}

void printKeypoints(const std::shared_ptr<std::vector<std::shared_ptr<op::Datum>>>& datumsPtr)
{
    try
    {
        // How to use the pose keypoints
        if (datumsPtr != nullptr && !datumsPtr->empty())
        {
            op::opLog("Body keypoints: " + datumsPtr->at(0)->poseKeypoints.toString(), op::Priority::High);
        }
        else
        {
            op::opLog("Nullptr or empty datumsPtr found.", op::Priority::High);
        }
    }
    catch (const std::exception& e)
    {
        op::error(e.what(), __LINE__, __FUNCTION__, __FILE__);
    }
}

int tutorialApiCpp()
{
    try
    {
        op::opLog("Starting OpenPose...", op::Priority::High);
        const auto opTimer = op::getTimerInit();

        // Configuring OpenPose
        op::opLog("Configuring OpenPose...", op::Priority::High);
        op::Wrapper opWrapper{ op::ThreadManagerMode::Asynchronous };
        // Set to single-thread (for sequential processing and/or debugging and/or reducing latency)
        if (FLAGS_disable_multi_thread)
        {
            opWrapper.disableMultiThreading();
        }

        // Starting OpenPose
        op::opLog("Starting thread(s)...", op::Priority::High);
        opWrapper.start();

        // ROS initialization
        ros::init(argc, argv, "openpose_ros");
        ros::NodeHandle nh;

        // Create a ROS subscriber for the image topic
        ros::Subscriber imageSubscriber = nh.subscribe("/usb_cam/image_raw", 1, imageCallback);

        // ROS spin
        ros::spin();

        // Measuring total time
        op::printTime(opTimer, "OpenPose successfully finished. Total time: ", " seconds.", op::Priority::High);

        // Return
        return 0;
    }
    catch (const std::exception&)
    {
        return -1;
    }
}

int main(int argc, char* argv[])
{
    // Parsing command line flags
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    // Running tutorialApiCpp
    return tutorialApiCpp();
}
