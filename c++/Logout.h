#include <string>
#include <vector>

#include "enum.h"

class LogOut{
    /*
    控制输出的媒介
    */
    std::vector<LogoutMediumType> logoutList;               //输出媒介列表

public:
    LogOut();
    LogOut(std::vector<LogoutMediumType> logoutList);       //根据输出媒介列表构造类
    LogoutMediumType addMedium(LogoutMediumType medium);    //添加输出媒介
    ~LogOut();
    

};