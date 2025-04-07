#ifndef __YBT_ROBOT_Y15_SPORT_CLIENT_HPP__
#define __YBT_ROBOT_Y15_SPORT_CLIENT_HPP__

#include <decl.hpp>  
 
namespace yobotics
{
namespace robot
{
namespace Y15  
{

/*
 * SportClient
 */
class SportClient
{
public:
    explicit SportClient();

    void Init();
  
    /*
     * @brief Damp
     * @api: 1001
     */
    int32_t Damp();

    /*
     * @brief BalanceStand
     * @api: 1002
     */
    int32_t BalanceStand();

    /*
     * @brief StopMove
     * @api: 1003
     */
    int32_t StopMove();

    /*
     * @brief StandUp
     * @api: 1004
     */
    int32_t StandUp();

    /*
     * @brief StandDown
     * @api: 1005
     */
    int32_t StandDown();

    /*
     * @brief RecoveryStand
     * @api: 1006
     */
    int32_t RecoveryStand();

    /*
     * @brief Euler
     * @api: 1007
     */
    int32_t Euler(float roll,float pitch,float yaw);

    /*
     * @brief Move
     * @api: 1008
     */
    int32_t Move(float vx,float vy,float vyaw);

    /*
     * @brief Sit
     * @api: 1009
     */
    int32_t Sit();

    /*
     * @brief RiseSit
     * @api: 1010
     */
    int32_t RiseSit();

    /*
     * @brief SwitchGait
     * @api: 1011~1016
     * gait=0,"trot"
     * gait=1,"slow trot"
     * gait=2,"walk"
     * gait=3,"flying trot"
     * gait=4,"bound"
     * gait=5,"ponk"
     */
    int32_t SwitchGait(int32_t gait);

    /*
     * @brief BodyHeight
     * @api: 1017
     */
    int32_t BodyHeight(float height);

    /*
     * @brief StepHeight
     * @api: 1018
     */ 
    int32_t StepHeight(float height);

    /*
     * @brief Hello
     * @api: 1019
     */ 
    int32_t Hello();

    /*
     * @brief SwitchJoystick
     * @api: 1020
     */ 
    int32_t SwitchJoystick(bool flag);

    /*
     * @brief ContinuousGait
     * @api: 1021
     */ 
    int32_t ContinuousGait(bool flag);

    /*
     * @brief Wallow
     * @api: 1022
     */ 
    int32_t Wallow();

    /*
     * @brief Scrape
     * @api: 1023
     */ 
    int32_t Scrape();

    /*
     * @brief Heart
     * @api: 1024 
     */ 
    int32_t Heart();

    /*
     * @brief Dance
     * @api: 1025
     */
    int32_t Dance();

    /*
     * @brief MoveToPose()
     * @api: 1026
     */
    int32_t MoveToPose(); 

    /*
     * @brief AI_FreeWalk()
     * @api: 1101
     */
    int32_t AI_FreeWalk(); 

    /*
     * @brief AI_WalkStair()
     * @api: 1102
     */  
    int32_t AI_WalkStair(); 

    /*
     * @brief AI_HandStand()
     * @api: 1103
     */
    int32_t AI_HandStand(); 

    /*
     * @brief AI_RecoveryStand()
     * @api: 1104
     */
    int32_t AI_RecoveryStand(); 

    /*
     * @brief Joint_control()
     * @api: 1201   
     */  
    int32_t Joint_control(); 
  
};

const int32_t trot  = 0; 
const int32_t slow_trot  = 1; 
const int32_t walk  = 2; 
const int32_t flying_trot  = 3; 
const int32_t bound  = 4; 
const int32_t pronk  = 5;   
  
}
}
}

#endif//__YBT_ROBOT_Y15_SPORT_CLIENT_HPP__ 