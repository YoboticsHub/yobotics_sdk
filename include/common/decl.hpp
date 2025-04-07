#ifndef __YBT_DECL_HPP__
#define __YBT_DECL_HPP__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <exception>
#include <execinfo.h>
#include <sched.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/sysinfo.h>
#include <sys/syscall.h>
#include <sys/resource.h> 
#include <sys/timerfd.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <limits.h>
#include <fcntl.h>
#include <dirent.h>
#include <utime.h>
#include <atomic>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <iomanip>  
#include <memory>
#include <regex>   
#include <thread> 
#include <lcm/lcm-cpp.hpp>
#include <lcm_types/cpp/sport_client_cmd_t.hpp>   
#include <lcm_types/cpp/imu_data_t.hpp>   
#include <lcm_types/cpp/motor_cmd_t.hpp>   
#include <lcm_types/cpp/motor_state_t.hpp>   
#include <lcm_types/cpp/rc_cmd_t.hpp>   
#include <Timer/Timer.hpp>    
#include <eigen3/Eigen/Dense>  

  
#define YBT_DECL_ERR(name, code, desc)   \
        const int32_t name = code; const std::string name##_DESC = desc;

#endif//__YBT_DECL_HPP__     