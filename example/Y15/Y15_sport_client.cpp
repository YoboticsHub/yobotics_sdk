#include "sport_client.hpp" 
#include "channel_publisher.hpp"  
#include "channel_subscriber.hpp" 
  
enum test_mode
{
  /*---Basic motion---*/
  normal_stand,
  balance_stand,
  velocity_move,
  stand_down,
  stand_up,
  damp,
  recovery_stand,
  step_adjust,  
  rl_move,
  /*---Special motion ---*/
  sit,
  rise_sit,
  Dance, 
  wallow,
  stand_height_adjust,   
  sport_height_adjust,
  gait_adjust,
  turn_rl_trot,
  //content,    
  stop_move = 99,
  joint_control=100     
};          
           
const int TEST_MODE =  sport_height_adjust;   
            
class Custom        
{            
public:    
  Custom()      
  {        
  };

  void RobotControl() 
  {    
    
    switch (TEST_MODE)
    {
    case normal_stand:    
        sport_client.StandUp(); 
        break;  
    case balance_stand:      
        sport_client.Euler(0.1, 0.2 , 0.3); // roll, pitch, yaw unit:rad
        sport_client.BalanceStand();   
        sleep(5);    
        sport_client.StopMove();

        break;        
    case velocity_move:     
        sport_client.ContinuousGait(true);  
        sport_client.Move(0.2, 0, 0.2);   
        sleep(5);    
        sport_client.StopMove();
        break;        
    case stand_down:        
        sport_client.StandDown();    
        break;    
    case stand_up:    
        sport_client.StandUp();
        break;   
    case recovery_stand:
        sport_client.RecoveryStand();  
        break;    
    case sit:  
        sport_client.Sit();
        break;  
    case rise_sit:
        sport_client.RiseSit();
        break;
    case wallow:    
        sport_client.Wallow();
        break;
    case stop_move:
        sport_client.StopMove();
        break;
    case Dance:  
        sport_client.Dance();
        break;
    case joint_control:
        sport_client.Joint_control(); 
        break;  
    case damp:
        sport_client.Damp();   
        break;
    case step_adjust:
        sport_client.ContinuousGait(true);    
        sport_client.StepHeight(0.1);  
        sleep(5);    
        sport_client.StepHeight(0.0);   
        sleep(5);
        sport_client.StepHeight(-0.05); 
        sleep(5);    
        sport_client.StopMove();                
        break;  

    case rl_move:
        sleep(1);
        sport_client.AI_FreeWalk();     
        sport_client.Move(0.7, 0, 0.0);   
        sleep(7);  
        sport_client.StopMove();  
        break; 

    case stand_height_adjust:
        sport_client.ContinuousGait(false);    
        sport_client.BodyHeight(0.03);   
        sleep(5);     
        sport_client.BodyHeight(-0.15);  
        sleep(5);    
        sport_client.StopMove();            
        break;
  
    case sport_height_adjust:  
        sport_client.ContinuousGait(true);    
        sport_client.BodyHeight(0.03);    
        sleep(5);    
        sport_client.BodyHeight(-0.15);
        sleep(5);    
        sport_client.StopMove();   
        break;

    case gait_adjust:
        sport_client.ContinuousGait(true);    
        sleep(5);
        sport_client.SwitchGait(yobotics::robot::Y15::trot);    
        sleep(5);    
        sport_client.SwitchGait(yobotics::robot::Y15::slow_trot);  
        sleep(5);    
        sport_client.SwitchGait(yobotics::robot::Y15::walk); 
        sleep(5);    
        sport_client.SwitchGait(yobotics::robot::Y15::flying_trot); 
        sleep(5);    
        sport_client.SwitchGait(yobotics::robot::Y15::bound);   
        sleep(5);    
        sport_client.SwitchGait(yobotics::robot::Y15::pronk);   
        sleep(5);    
        sport_client.StopMove();  
        break;
  
    case turn_rl_trot:
        sport_client.Move(0.5, 0, 0.0);    
        sport_client.ContinuousGait(true);    
        sleep(3);    
        sport_client.AI_FreeWalk();     
        sleep(5);
        break;
  
                    
    default:   
        break;
    }

  }

  yobotics::robot::Y15::SportClient sport_client;

}; 

int main(int argc, char **argv)
{  
  yobotics::robot::Y15::SportClient sport_client;
  Custom custom;     
  sport_client.StandUp();    
  sleep(3);    
  custom.RobotControl();
    
  while (1)    
  { 
    sleep(1);
  }
  return 0;  
}  
