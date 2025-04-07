#ifndef __YBT_ROBOT_Y15_SPORT_API_HPP__
#define __YBT_ROBOT_Y15_SPORT_API_HPP__

#include <decl.hpp>  

namespace yobotics
{
namespace robot
{
namespace Y15 
{
/*service name*/
const std::string ROBOT_SPORT_SERVICE_NAME = "sport";  

/*api version*/
const std::string ROBOT_SPORT_API_VERSION = "1.0.0.0";

/*api id*/
const int32_t ROBOT_SPORT_API_ID_INIT               = 1000;
const int32_t ROBOT_SPORT_API_ID_DAMP               = 1001;
const int32_t ROBOT_SPORT_API_ID_BALANCE_STAND      = 1002;
const int32_t ROBOT_SPORT_API_ID_STOP_MOVE          = 1003;
const int32_t ROBOT_SPORT_API_ID_STAND_UP           = 1004;
const int32_t ROBOT_SPORT_API_ID_STAND_DOWN         = 1005; 
const int32_t ROBOT_SPORT_API_ID_RECOVERY_STAND     = 1006; 
const int32_t ROBOT_SPORT_API_ID_EULER              = 1007; 
const int32_t ROBOT_SPORT_API_ID_MOVE               = 1008; 
const int32_t ROBOT_SPORT_API_ID_SIT                = 1009; 
const int32_t ROBOT_SPORT_API_ID_RISE_SIT           = 1010; 
const int32_t ROBOT_SPORT_API_ID_GAIT_TROT          = 1011; 
const int32_t ROBOT_SPORT_API_ID_GAIT_SLOWTROT      = 1012; 
const int32_t ROBOT_SPORT_API_ID_GAIT_WALK          = 1013; 
const int32_t ROBOT_SPORT_API_ID_GAIT_FLYTROT       = 1014; 
const int32_t ROBOT_SPORT_API_ID_GAIT_BOUND         = 1015;  
const int32_t ROBOT_SPORT_API_ID_GAIT_PONK          = 1016; 
const int32_t ROBOT_SPORT_API_ID_BODY_HEIGHT        = 1017; 
const int32_t ROBOT_SPORT_API_ID_STEP_HEIGHT        = 1018; 
const int32_t ROBOT_SPORT_API_ID_HELLO              = 1019; 
const int32_t ROBOT_SPORT_API_ID_SWITCH_JOYSTICK    = 1020;   
const int32_t ROBOT_SPORT_API_ID_CONTIOUS_GAIT      = 1021; 
const int32_t ROBOT_SPORT_API_ID_WALLOW             = 1022; 
const int32_t ROBOT_SPORT_API_ID_SCRAPE             = 1023; 
const int32_t ROBOT_SPORT_API_ID_HEART              = 1024; 
const int32_t ROBOT_SPORT_API_ID_DANCE              = 1025;
const int32_t ROBOT_SPORT_API_ID_MOVETOPOSE         = 1026;

const int32_t ROBOT_SPORT_API_ID_AI_FREEWALK        = 1101; 
const int32_t ROBOT_SPORT_API_ID_AI_WALKSTAIR       = 1102;  
const int32_t ROBOT_SPORT_API_ID_AI_HANDSTAND       = 1103; 
const int32_t ROBOT_SPORT_API_ID_AI_RECOVERYSTAND   = 1104; 
 
const int32_t ROBOT_SPORT_API_ID_JOINT_CONTROL      = 1201;   

  
}
}
}

#endif //__YBT_ROBOT_Y15_SPORT_API_HPP__
