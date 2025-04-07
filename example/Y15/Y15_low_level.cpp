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
  
    void Init();
    void Start();
    void Task();
    void RunTaskWithInterval(std::atomic<bool>& running);

    motor_cmd_t *motorCmd;

    ChannelPublisher* example_pub;   
    ChannelSubscriber* example_sub;   
  
    motor_state_t _motorState_lcmt{};
    imu_data_t _imuData_lcmt{};      
    rc_cmd_t _rcCmd_lcmt{};  

    Eigen::Matrix<float, 3, 1> fold_jpos[4];
    Eigen::Matrix<float, 3, 1> stand_jpos[4];
    Eigen::Matrix<float, 3, 1> now_jpos[4];
    Eigen::Matrix<float ,3, 1> zero_jpos;

   void _SetJPosInterPts( 
        const size_t & curr_iter, size_t max_iter, int leg,
        const Eigen::Matrix<float, 3, 1> & ini, const Eigen::Matrix<float, 3, 1> & fin);

    void jointPDControl(
    int leg, Eigen::Matrix<float, 3, 1> qDes, Eigen::Matrix<float, 3, 1> qdDes) ;  
  
private:
    float Kp = 20.0;
    float Kd = 2;  
    std::atomic<bool> running;   
};


Custom::Custom()    
{
    example_pub = new ChannelPublisher(&_lcm);
    example_sub = new ChannelSubscriber(&_lcm);
    motorCmd = new motor_cmd_t();   
}


Custom::~Custom()
{
    delete example_pub;       
    delete example_sub;
    delete motorCmd;  
}  


void Custom::Init()
{
    fold_jpos[0] << -0.5f, -1.4f, 2.7f;
    fold_jpos[1] << 0.5f, -1.4f, 2.7f;
    fold_jpos[2] << -0.5f, -1.4f, 2.7f;
    fold_jpos[3] << 0.5f, -1.4f, 2.7f;

    for(size_t i(0); i<4; ++i){
    stand_jpos[i] << 0.f, -.8f, 1.6f;
    }

    zero_jpos  << 0.0f, 0.0f, 0.0f;  
  
} 


void Custom::jointPDControl(int leg, Eigen::Matrix<float, 3, 1>  qDes, Eigen::Matrix<float, 3, 1>  qdDes){

    motorCmd->q_des_abad[leg]= qDes[0];
    motorCmd->q_des_hip[leg]= qDes[1];  
    motorCmd->q_des_knee[leg]= qDes[2];
    motorCmd->qd_des_abad[leg]= qdDes[0];
    motorCmd->qd_des_hip[leg]= qdDes[1];
    motorCmd->qd_des_knee[leg]= qdDes[2];
    motorCmd->kp_abad[leg]= Kp;
    motorCmd->kp_hip[leg]= Kp;  
    motorCmd->kp_knee[leg]= Kp;        
    motorCmd->kd_abad[leg]= Kd;  
    motorCmd->kd_hip[leg]= Kd;  
    motorCmd->kd_knee[leg]= Kd;
 
}

void Custom::_SetJPosInterPts(
        const size_t & curr_iter, size_t max_iter, int leg,
        const Eigen::Matrix<float, 3, 1>  & ini, const Eigen::Matrix<float, 3, 1>  & fin){

    float a(0.f);
    float b(1.f);

    if(curr_iter <= max_iter) {
        b = (float)curr_iter/(float)max_iter;
        a = 1.f - b;  
    }

    Eigen::Matrix<float, 3, 1>  inter_pos = a * ini + b * fin;
    jointPDControl(leg, inter_pos, zero_jpos);

}

void Custom::Task(){  

    example_sub->read(&_motorState_lcmt);    

    for(int i=0;i<4;i++){  
        now_jpos[i][0] = _motorState_lcmt.q_abad[i];  
        now_jpos[i][1] = _motorState_lcmt.q_hip[i];
        now_jpos[i][2] = _motorState_lcmt.q_knee[i];   
        motorCmd->kp_abad[1]=0;    
        motorCmd->kd_abad[1]=0; 
        motorCmd->kp_hip[1]=0;    
        motorCmd->kd_hip[1]=0; 
        motorCmd->kp_knee[1]=0;    
        motorCmd->kd_knee[1]=0; 
    }  

    static int count=0;  
    count++ ;      
    motorCmd->q_des_knee[1]= 1.8f + 0.1*sin(2*3.1415926*count/500);  //-0.4为了避开限位  
    motorCmd->qd_des_knee[1]=0;
    motorCmd->kp_knee[1]=Kp;    
    motorCmd->kd_knee[1]=Kd;  

    example_pub->write(motorCmd);     

} 

void Custom::RunTaskWithInterval(std::atomic<bool>& running) {
    using namespace std::chrono;  

    milliseconds interval(2);  //ms 

    while (running) {    
        Task();   
        std::this_thread::sleep_for(interval); 
    }  
}

void Custom::Start()
{
    std::atomic<bool> running(true);   

    std::thread taskThread(&Custom::RunTaskWithInterval, this, std::ref(running));

    std::this_thread::sleep_for(std::chrono::seconds(500)); 
    running = false; // 

    taskThread.join();    
  
    std::cout << "Task thread has stopped." << std::endl;  
    
}
  

int main(int argc, char **argv)
{  
  yobotics::robot::Y15::SportClient sport_client;

  Custom custom;  
  custom.Init();  
  custom.Start(); 

  while (1)
  {
    sleep(10);
  }
  return 0;    

}
