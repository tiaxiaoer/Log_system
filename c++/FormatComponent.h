
#include <memory>


#include "LogInfo.h"


// 日志格式化组件基类
class FormatComponent
{
public:
    using ptr=std::shared_ptr<FormatComponent>;     //定义类型别名，作用域为类作用域，类内直接访问

    virtual ~FormatComponent(){}
    // 将消息内容流入out流当中
    virtual void format(std::ostream &out, const LogInfo &logInfo) = 0;
};

class DateFormatComponent : public FormatComponent
{

};

class LevelFormatComponent : public FormatComponent
{
    
};

class FilenameFormatComponent : public FormatComponent
{
    
};

class LineFormatComponent : public FormatComponent
{
    
};

class ThreadIdFormatComponent : public FormatComponent
{

};

class ChangeLineFormatComponent : public FormatComponent
{

};

class MessageBodyFormatComponent : public FormatComponent
{
    
};

class TabFormatComponent : public FormatComponent
{
    
};

class LoggerNameFormatComponent : public FormatComponent
{

};
