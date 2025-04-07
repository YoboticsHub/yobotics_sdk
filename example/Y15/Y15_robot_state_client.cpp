#include "sport_client.hpp"
#include "channel_publisher.hpp"  
#include "channel_subscriber.hpp" 

using namespace yobotics::robot;  
using namespace yobotics::robot::Y15;

lcm::LCM _lcm("udpm://239.255.76.67:7667?ttl=255"); 

class Custom  
{  
public: 
    explicit Custom();
    ~Custom();
    void task();
    ChannelSubscriber* example_sub; 

private: 
    motor_state_t _motorState_lcmt{};  
    imu_data_t _imuData_lcmt{};  
    rc_cmd_t _rcCmd_lcmt{}; 
};
 
Custom::Custom()
{      
    example_sub = new ChannelSubscriber(&_lcm);  
}  

Custom::~Custom()
{       
    delete example_sub;  
}

void Custom::task() 
{
  example_sub->read(&_motorState_lcmt);
  example_sub->read(&_imuData_lcmt);
  example_sub->read(&_rcCmd_lcmt);
  std::cout << "_motorState_msg" << std::endl;
  std::cout << "_motorState.q_abad[0]:" <<_motorState_lcmt.q_abad[0] << std::endl;
  std::cout << "_motorState.q_hip[0]:" <<_motorState_lcmt.q_hip[0] << std::endl;
  std::cout << "_motorState.q_knee[0]:" <<_motorState_lcmt.q_knee[0] << std::endl;
  std::cout << "_motorState.qd_abad[0]:" <<_motorState_lcmt.qd_abad[0] << std::endl;
  std::cout << "_motorState.qd_hip[0]:" <<_motorState_lcmt.qd_hip[0] << std::endl;
  std::cout << "_motorState.qd_knee[0]:" <<_motorState_lcmt.qd_knee[0] << std::endl;
  std::cout << "_motorState.tau_abad[0]:" <<_motorState_lcmt.tau_abad[0] << std::endl;
  std::cout << "_motorState.tau_hip[0]:" <<_motorState_lcmt.tau_hip[0] << std::endl;
  std::cout << "_motorState.tau_knee[0]:" <<_motorState_lcmt.tau_knee[0] << std::endl;
  std::cout << "_motorState.footForce[0]:" <<_motorState_lcmt.footForce[0] << std::endl;
  std::cout << "......"  << std::endl;  
  std::cout << "imu_msg" << std::endl;
  std::cout << "rpy[0]:" <<_imuData_lcmt.rpy[0] << std::endl;
  std::cout << "rpy[1]:" <<_imuData_lcmt.rpy[1] << std::endl;
  std::cout << "rpy[2]:" <<_imuData_lcmt.rpy[2] << std::endl;
  std::cout << "accelerometer[0]" <<_imuData_lcmt.accelerometer[0] << std::endl;
  std::cout << "accelerometer[1]" <<_imuData_lcmt.accelerometer[1] << std::endl;
  std::cout << "accelerometer[2]" <<_imuData_lcmt.accelerometer[2] << std::endl;
  std::cout << "......"  << std::endl;
  std::cout << "rc_cmd" << std::endl;   //用于向上层算法反馈遥控器数据，需上层算法响应
  std::cout << "linearVelX:" <<_rcCmd_lcmt.linearVelX << std::endl;
  std::cout << "linearVelY:" <<_rcCmd_lcmt.linearVelY << std::endl;
  std::cout << "linearVelZ:" <<_rcCmd_lcmt.linearVelZ << std::endl;  
  std::cout << "angularVelX:" <<_rcCmd_lcmt.angularVelX << std::endl;
  std::cout << "angularVelZ:" <<_rcCmd_lcmt.angularVelZ << std::endl;
  std::cout << "angularVelY:" <<_rcCmd_lcmt.angularVelY << std::endl;  
  std::cout << "roll:" <<_rcCmd_lcmt.roll << std::endl;
  std::cout << "yaw:" <<_rcCmd_lcmt.yaw << std::endl;
  std::cout << "pitch:" <<_rcCmd_lcmt.pitch << std::endl;
  std::cout << "bodyHeight:" <<_rcCmd_lcmt.bodyHeight << std::endl;  
  std::cout << "stepHeight:" <<_rcCmd_lcmt.stepHeight << std::endl;
  std::cout << "......"  << std::endl;


}

int main(int argc, char **argv)
{  

  Custom custom;
  
  while (1)
  {
    custom.task();  
    sleep(1);
  } 
  return 0;    

}  

