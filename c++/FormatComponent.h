
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

class DateYearFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class DateMonthFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class DateDayFormatComponent : public FormatComponent{
    void format(std::ostream &out, const LogInfo &logInfo) override;
}

class DateHourFormatComponent : public FormatComponent{
    void format(std::ostream &out, const LogInfo &logInfo) override; 
}

class DateMinuteFormatComponent : public FormatComponent{
    void format(std::ostream &out, const LogInfo &logInfo) override;
}

class DateSecondFormatComponent : public FormatComponent{
    void format(std::ostream &out, const LogInfo &logInfo) override;
}

class LevelFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class FilenameFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class LineFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class ThreadIdFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class ChangeLineFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class MessageBodyFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class TabFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class LoggerNameFormatComponent : public FormatComponent
{
    void format(std::ostream &out, const LogInfo &logInfo) override;
};

class ModFormatComponent : public FormatComponent{
    void format(std::ostream &out, const LogInfo &logInfo) override; 
}