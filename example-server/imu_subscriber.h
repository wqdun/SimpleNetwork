#ifndef _IMU_SUBSCRIBER_H_
#define _IMU_SUBSCRIBER_H_

#include <ros/ros.h>
#include "sc_msgs/imu5651.h"


class ImuSubscriber {
public:
    ImuSubscriber(ros::NodeHandle node);
    ~ImuSubscriber();
    void RegisterCBs();


private:
    void ClientCB(const sc_msgs::imu5651::ConstPtr& pImu5651Msg);

    ros::NodeHandle nh_;
    ros::Subscriber imuSub_;
};


#endif
