#include <string>

#include "LogFormatter.h"
#include "enum.h"


class Logger {
    /*
    负责对日志消息模块，日志格式化模块，日志消息落地模块进行整合
    一个日志器支持多个落地
    一个日志器支持 一个日志格式
    日志器是日志打印的基本单位
    日志器分为同步日志器和异步日志器
    */
private:
    LogoutSynAsyncType sync_or_async;       // 同步还是异步
    LogoutMediumType medium;                // 输出到什么地方
    LogFormatter formatter;                 // 日志格式

    std::string logger_name;                // 日志器名称
    int logger_id;                          // 日志器ID

public:
    /** Initialize your data structure here. */
    Logger() {

    }
    Logger(LogoutSynAsyncType sync_or_async, LogoutMediumType medium, LogFormatter formatter, std::string logger_name, int logger_id) {
        this->sync_or_async = sync_or_async;
        this->medium = medium;
        this->formatter = formatter;
        this->logger_name = logger_name;
        this->logger_id = logger_id;
    }

    void setSyncOrAsync(LogoutSynAsyncType sync_or_async) {
        this->sync_or_async = sync_or_async;
    }

    void setMedium(LogoutMediumType medium) {
        this->medium = medium;  
    }

    void setFormatter(LogFormatter formatter) {
        this->formatter = formatter; 
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, std::string message) {
        
    }

    int getLoggerId() {
        return this->logger_id; 
    }

    std::string getLoggerName() {
        return this->logger_name;
    }
};