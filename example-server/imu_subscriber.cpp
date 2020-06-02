#include "imu_subscriber.h"

#include <glog/logging.h>


ImuSubscriber::ImuSubscriber(ros::NodeHandle node)
    : nh_(node)
    , string2Send_("")
{
    LOG(INFO) << __FUNCTION__ << " start.";
}

ImuSubscriber::~ImuSubscriber() {
    LOG(INFO) << __FUNCTION__ << " start.";
}

void ImuSubscriber::RegisterCBs() {
    imuSub_ = nh_.subscribe("imu_string", 10, &ImuSubscriber::ClientCB, this);
}

void ImuSubscriber::ClientCB(const sc_msgs::imu5651::ConstPtr& pImu5651Msg) {
    LOG(INFO) << __FUNCTION__ << " start.";

    string2Send_ = pImu5651Msg->latitude_gpgga;
}

std::string ImuSubscriber::GetString2Send() {
    LOG(INFO) << __FUNCTION__ << " start.";

    return string2Send_;
}

