# **yobotics_sdk** #
yobotics robot sdk.
## **Prebuild environment** ##
- OS (> Ubuntu 16.04 LTS) 
- CPU (x86_64)
- LCM - https://lcm-proj.github.io/ (Please make it sure that you have a java to let lcm compile java-extension together)
- Eigen - http://eigen.tuxfamily.org
## **Build examples** ##
To build the examples inside this repository:
```c++
mkdir build
cd build
cmake ..
make -j4
```
## **Installation** ##
To build your own application with the SDK, you can install the yobotics_sdk to your system directory:
```c++
mkdir build
cd build
cmake ..
make
sudo make install
```
Or install yobotics_sdk to a specified directory:
```c++
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/yobotics_sdk
make
sudo make install
```
Note that if you install the library to other places other than /opt/yobotics_sdk, you need to make sure the path is added to "${CMAKE_PREFIX_PATH}" so that cmake can find it with "find_package()".
## **Notice** ##
For more reference information, please contact the company(https://yobotics.cn/). The information can be obtained by reaching out to them.



