#pragma once

enum class LogLevel {
    TRACE,   // 最详细跟踪
    DEBUG,   // 调试信息
    INFO,    // 常规运行状态
    WARNING, // 潜在问题
    ERROR,   // 错误事件
    FATAL,   // 严重错误
    UNKNOWN  // 未知级别
};

enum class LogoutMediumType {
    CONSOLE,     // 控制台输出
    FILE,        // 文件输出
    ROLL_FILE,   // 滚动文件输出
    DB,          // 数据库输出
    SOCKET       // 网络输出
};

enum class LogoutSynAsyncType {
    SYNC,    // 同步输出
    ASYNC    // 异步输出 
};

// 日志占位符
enum class LogPlaceholder {
    DATE_YEAR,           //日期年份
    DATE_MONTH,          //日期月份
    DATE_DAY,            //日期日期
    DATE_HOUR,           //日期小时
    DATE_MINUTE,         //日期分钟
    DATE_SECOND,         //日期秒钟
    
    LEVEL,          //日志级别
    FILENAME,       //文件名
    LINE,           //行号
    THREAD_ID,      //线程ID
    MESSAGE,        //消息主体
    NEWLINE,        //换行符
    TAB,            //制表符
    LOGGER_NAME,    //日志器名称

    ORIGINAL_CHAR,   //原始字符

    WRONG_PLACEHOLDER  //错误的占位符
};