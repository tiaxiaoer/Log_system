

#include "LogFormatter.h"
#include "enum.h"



/*
void LogFormatter::setComponentList(){
    DateFormatComponent dateComponent;
    LevelFormatComponent levelComponent;
    FilenameFormatComponent filenameComponent;
    LineFormatComponent lineComponent;
    ThreadIdFormatComponent threadIdComponent;
    ChangeLineFormatComponent changeLineComponent;
    MessageFormatComponent messageComponent;
    TabFormatComponent tabComponent;
    LoggerNameFormatComponent loggerNameComponent;
    this->componentList.push_back(dateComponent());
    this->componentList.push_back(dateComponent());
    this->componentList.push_back(LevelFormatComponent());

}
*/

/* 将字符标识符转换为日志占位符枚举
 * @brief 实现格式字符到枚举值的映射转换
 * @param placeholder 格式标识字符，例如：
 *                    - 日期相关: Y(年)/M(月)/D(日)/h(时)/m(分)/s(秒)
 *                    - 日志组件: r(级别)/f(文件名)/l(行号)/i(线程ID)/b(消息主体)
 *                    - 格式控制: n(换行)/t(制表符)/g(记录器名称)
 * @return LogPlaceholder 对应的日志格式占位符枚举值
 * @note 若传入未定义的字符将导致未处理分支，建议后续增加异常处理
 */
static std::LogPlaceholder FormatConvert::toPlaceholder(char placeholder)
{
    switch(placeholder){
        // 日期时间组件
        case 'Y': return LogPlaceholder::DATE_YEAR;   // 年
        case 'M': return LogPlaceholder::DATE_MONTH;  // 月
        case 'D': return LogPlaceholder::DATE_DAY;    // 日
        case 'h': return LogPlaceholder::DATE_HOUR;   // 时
        case 'm': return LogPlaceholder::DATE_MINUTE; // 分
        case 's': return LogPlaceholder::DATE_SECOND; // 秒

        // 日志组件
        case 'r': return LogPlaceholder::LEVEL;       // 日志级别
        case 'f': return LogPlaceholder::FILENAME;    // 源代码文件名
        case 'l': return LogPlaceholder::LINE;        // 代码行号
        case 'i': return LogPlaceholder::THREAD_ID;   // 线程ID
        case 'b': return LogPlaceholder::MESSAGE;     // 消息内容

        // 特殊符号
        case 'n': return LogPlaceholder::NEWLINE;     // 换行符
        case 't': return LogPlaceholder::TAB;          // 制表符
        case 'g': return LogPlaceholder::LOGGER_NAME; // 记录器名称
    }
}


void LogFormatter::setFormatFunc(){
    /*设置格式化占位符对应的格式化函数指针*/
    this->formatFunc.push_back(DateYearFormatComponent::format);
    this->formatFunc.push_back(DateMonthFormatComponent::format);
    this->formatFunc.push_back(DateDayFormatComponent::format);
    this->formatFunc.push_back(DateHourFormatComponent::format);

    this->formatFunc.push_back(DateMinuteFormatComponent::format);
    this->formatFunc.push_back(DateSecondFormatComponent::format);
    this->formatFunc.push_back(LevelFormatComponent::format);
    this->formatFunc.push_back(FilenameFormatComponent::format);

    this->formatFunc.push_back(LineFormatComponent::format);
    this->formatFunc.push_back(ThreadIdFormatComponent::format);
    this->formatFunc.push_back(ChangeLineFormatComponent::format);
    this->formatFunc.push_back(MessageFormatComponent::format);

    this->formatFunc.push_back(TabFormatComponent::format);
    this->formatFunc.push_back(LoggerNameFormatComponent::format);
}

/* 获取与指定日志占位符对应的格式化函数指针
 * @brief 通过占位符枚举获取对应的日志格式处理函数
 * @param placeholder 日志格式占位符枚举值，参考LogPlaceholder定义
 * @return 返回对应占位符的格式化函数指针
 * @note 调用者需确保传入有效的枚举值，否则可能导致未定义行为
 */
function<void> LogFormatter::getFormatFunc(LogPlaceholder placeholder){
    return this->formatFunc[placeholder];
}

LogFormatter::LogFormatter(){

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
LogFormatter::LogFormatter(std::string format){
    for(int i=0; i<)
    this->format = format;
    if(format.size()==1){
        if(format[0]=='%'){
            this->formatFlag = false;
            return;
        }
        if(format[0]!='%'){
            //说明是消息主体
            this->formatFlag = true;
            this->placeholderList.push_back(getFormatComponentPtr(LogPlaceholder::MESSAGE));
            return;
        }
    }
    for(int i=0, j=1; j<=format.size(); ){
        if(format[i]=='%' && i<format.size()){
            j=i+1;
            if(j>=format.size()){
                this->formatFlag = false;
                return;
            }
            else{
                this->placeholderList.push_back(FormatConvert::toPlaceholder(format[j]));
            }
            
        }

        /*未完成*/
        while(j<format.size() && format[j]!='%'){
            if(format[i]=='%'){
                this->placeholderList.push_back();
            }
        }
    }
}

/*
void LogFormatter::setFormat(std::string format){
    
}
*/

std::string LogFormatter::formatMessage(LogInfo logInfo){

}

LogFormatter::~LogFormatter(){

}
  
