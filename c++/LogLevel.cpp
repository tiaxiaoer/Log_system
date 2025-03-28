

#include "LogLevel.h"

std::string Loglevel::toString(LogLevel level) {
    switch (level) {
        case LogLevel::TRACE: return "TRACE";
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default: {
            // 处理未知的日志级别
            // 你可以选择抛出异常、返回默认值或其他适当的处理方式
            return "UNKNOWN";  // 这里返回一个默认值，你也可以根据需要修改
        };
    }
}

LogLevel Loglevel::fromString(std::string level){
    if(level == "TRACE"){return LogLevel::TRACE;}
    else if(level == "DEBUG"){return LogLevel::DEBUG;}
    else if(level == "INFO"){return LogLevel::INFO;}
    else if(level == "WARNING"){return LogLevel::WARNING;}
    else if(level == "ERROR"){return LogLevel::ERROR;}
    else if(level == "FATAL"){return LogLevel::FATAL;}
    else{return LogLevel::UNKNOWN;}
}