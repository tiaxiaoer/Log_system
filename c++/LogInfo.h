#include <iostream>
#include <ctime>
#include <thread>

#include "enum.h"
#include "Logger.h"

class LogInfo{
    /*
    时间（年月日时分秒）
    日志等级
    文件名和行号
    线程ID
    日志器名称
    消息主体
    */
    std::time_t time;
    LogLevel level;
    std::string filename;
    unsigned int line;
    
    std::thread::id thread_id;
    Logger logger;
    std::string message;
};