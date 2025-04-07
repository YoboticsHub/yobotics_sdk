#ifndef __YBT_ROBOT_SDK_CHANNEL_SUBSCRIBER_HPP__
#define __YBT_ROBOT_SDK_CHANNEL_SUBSCRIBER_HPP__

#include "channel_name.hpp"
  
namespace yobotics
{    
namespace robot
{
class ChannelSubscriber{
public:  
    ChannelSubscriber(lcm::LCM *lcm);
    ~ChannelSubscriber();
    void read(motor_state_t *info);
    void read(imu_data_t *info);
    void read(rc_cmd_t *info);
    void read_handle(const lcm::ReceiveBuffer *rbuf, const std::string &chan);
    void zero();
    void handleInterfaceLCM()
    {
      while ( !_interfaceLcmQuit ) {
        _lcm->handle();
      }
    }  
    
private:           
    lcm::LCM *_lcm;  
    volatile bool _interfaceLcmQuit = false;  
    std::thread _ChannelSubscriberThread;  
    motor_state_t _motorState_lcmt{};
    imu_data_t _imuData_lcmt{};
    rc_cmd_t _rcCmd_lcmt{};  
        
    std::mutex _lcm_ready_mutex;
    std::condition_variable _lcm_ready_cv;
    bool _lcm_ready = false; 
};

  
}
}    

#endif//__YBT_ROBOT_SDK_CHANNEL_SUBSCRIBER_HPP__
  