#include "imu_subscriber.h"

#include <glog/logging.h>


ImuSubscriber::ImuSubscriber(ros::NodeHandle node)
    : nh_(node)
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
    DLOG(INFO) << __FUNCTION__ << " start.";

    isSaveLidar_ = pClientMsg->is_record;
    isSolution_ = pClientMsg->is_solution;

    if (IsMarksCountUpdated(pClientMsg->marks_count)) {
        WriteMarkFile(pClientMsg);
        UpdatePreviousMarksCount(pClientMsg->marks_count);
    }
    // else: MarksCount Not Updated, No add 2 3 4

    if (previousIsSolution_ != pClientMsg->is_solution) {
        WriteSolutionToMarkFile(pClientMsg);
        previousIsSolution_ = pClientMsg->is_solution;
    }
    // else: IsSolution_ Not Updated, No add 0 1
}

