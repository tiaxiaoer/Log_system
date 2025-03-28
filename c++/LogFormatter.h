#include <string>
#include <vector>

#include "LogInfo.h"
#include "enum.h"
#include "FormatComponent.h"


class FormatConvert{
    /* 
        将占位符转换对应字符串
        将字符串转换对应占位符
     */
    static std::string toString(PlaceholderType placeholder);
    static std::LogPlaceholder toPlaceholder(char placeholder);
};


class LogFormatter {
    /*
    **日志格式化模块主要负责：
    **约定各种格式化占位符
    **允许用户传入自定义格式化字符串，在内部解析
    **把用户传入的消息主体格式化为日志消息
    */

    /*
    **  %d  时间（date）
    **  %r  日志等级（rate）
    **  %f  文件名（file）
    **  %l  行数（line）
    **  %i  线程ID（id）
    **  %b  消息主体（body）
    **  %n  换行符（\n）
    **  %t  水平制表符（\t）
    **  %g  日志器名称（logger_name）
    */
private:
    std::string format;         // 格式化字符串
    std::string message;        // 消息主体
    std::vector<LogPlaceholder> placeholderList;    // 占位符列表
    std::vector<FormatComponent> componentList;     // 格式化组件列表

    vector< function<void> > formatFunc;  
    // 格式化函数，存放的是用于将格式化占位符转换为格式化字符串的函数，
    //即LogFormatComponent的各子类中的format方法

    bool formatFlag=true;    //用于标志format是否合法，false表示不合法，true表示合法

    void setComponentList();    // 设置格式化组件列表
    void setFormatFunc();       // 设置格式化函数列表
    

public:
    LogFormatter();
    // 传入格式化字符串，进行初始化
    LogFormatter(std::string format);       //没有检查format是否为空，需要在调用处检查
    //设置格式化字符串，如果设置成功，返回true，否则返回false
    //void setFormat(std::string format);
    //传入消息主题，返回格式化后的日志消息
    std::string formatMessage(LogInfo logInfo);
    // 获取占位符列表
    function<void> getFormatFunc(LogPlaceholder placeholder);  
    ~LogFormatter();

}
