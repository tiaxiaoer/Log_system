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
private:
    std::time_t time;
    enum LogLevel level;
    std::string filename;
    unsigned int line;
    
    std::thread::id thread_id;
    Logger logger;
    std::string message;

public:
    LogInfo(std::time_t time, LogLevel level, std::string filename, unsigned int line, std::thread::id thread_id, Logger logger, std::string message) : 
        time(time), level(level), filename(filename), line(line), thread_id(thread_id), logger(logger), message(message) {}

    int getTimeYear() const { return 1900 + std::localtime(&time)->tm_year; }
    int getTimeMonth() const { return 1 + std::localtime(&time)->tm_mon; }
    int getTimeDay() const { return std::localtime(&time)->tm_mday; }
    int getTimeHour() const { return std::localtime(&time)->tm_hour; }
    int getTimeMinute() const { return std::localtime(&time)->tm_min; }
    int getTimeSecond() const { return std::localtime(&time)->tm_sec;}

    std::string getLevel() const { return level; }
    std::string getFilename() const { return filename; }
    unsigned int getLine() const { return line;}
    std::thread::id getThreadId() const { return thread_id; }
    
    std::string getMessage() const { return message; }
    std::string getLoggerName() const { return logger.getName(); }
    std::string getLoggerLevel() const { return logger.getLevel(); }
};