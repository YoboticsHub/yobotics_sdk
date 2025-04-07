#ifndef __YBT_ROBOT_SDK_CHANNEL_NAME_HPP__
#define __YBT_ROBOT_SDK_CHANNEL_NAME_HPP__

#include <string>
#include <memory>
#include <utility>
#include <thread> 
#include <lcm/lcm-cpp.hpp>
#include <lcm_types/cpp/sport_client_cmd_t.hpp>   
#include <lcm_types/cpp/imu_data_t.hpp>   
#include <lcm_types/cpp/motor_cmd_t.hpp>     
#include <lcm_types/cpp/motor_state_t.hpp>   
#include <lcm_types/cpp/rc_cmd_t.hpp>   
#include <Timer/Timer.hpp>   
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <mutex>
#include <condition_variable> 

namespace yobotics  
{
namespace robot 
{  

const std::string ROBOT_SDK_TOPIC_LOWCMD ="MOTOR_CMD";
const std::string ROBOT_SDK_TOPIC_LOWSTATE ="MOTOR_STATE";
const std::string ROBOT_SDK_TOPIC_IMU ="IMU_DATA" ;
const std::string ROBOT_SDK_TOPIC_RCSTATE = "CMD" ;
const std::string ROBOT_SDK_SPORT = "UPPER_dogCONTROL" ;

/*
 * @brief
 * @class: ChannelNamer    
 */ 
class ChannelNamer
{
public:
    ChannelNamer();
    ~ChannelNamer();

protected:
    std::string GetSendChannelName(const std::string& name);
    std::string GetRecvChannelName(const std::string& name);
};

using ChannelNamerPtr = std::shared_ptr<ChannelNamer>;

}
}

#endif//__YBT_ROBOT_SDK_CHANNEL_NAME_HPP__ 