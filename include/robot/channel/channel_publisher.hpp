#ifndef __YBT_ROBOT_SDK_CHANNEL_PUBLISHER_HPP__
#define __YBT_ROBOT_SDK_CHANNEL_PUBLISHER_HPP__

#include "channel_name.hpp"
 
namespace yobotics  
{
namespace robot
{

class ChannelPublisher{
public:
    ChannelPublisher(lcm::LCM *lcm);
    void write(motor_cmd_t *info);
    void write(sport_client_cmd_t *info);

private:  
    lcm::LCM *_lcm;
    motor_cmd_t motor_cmd{};
    sport_client_cmd_t sport_client_cmd{};   
};


}
}
#endif//__YBT_ROBOT_SDK_CHANNEL_PUBLISHER_HPP    