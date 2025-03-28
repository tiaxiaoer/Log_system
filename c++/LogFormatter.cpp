

#include "LogFormatter.h"
#include "enum.h"




void LogFormatter::setComponentList(){
    /*设置格式化组件列表*/

    this->componentList.push_back(DateYearFormatComponent());
    this->componentList.push_back(DateMonthFormatComponent());
    this->componentList.push_back(DateDayFormatComponent());
    this->componentList.push_back(DateHourFormatComponent());
    this->componentList.push_back(DateMinuteFormatComponent());
    this->componentList.push_back(DateSecondFormatComponent());

    this->componentList.push_back(LevelFormatComponent());
    this->componentList.push_back(FilenameFormatComponent());
    this->componentList.push_back(LineFormatComponent());
    this->componentList.push_back(ThreadIdFormatComponent());
    this->componentList.push_back(ChangeLineFormatComponent());

    this->componentList.push_back(MessageBodyFormatComponent());
    this->componentList.push_back(TabFormatComponent());
    this->componentList.push_back(LoggerNameFormatComponent());
    this->componentList.push_back(ModFormatComponent());


}

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
        case 't': return LogPlaceholder::TAB;         // 制表符
        case 'g': return LogPlaceholder::LOGGER_NAME; // 记录器名称
        default:  return LogPlaceholder::WRONG_PLACEHOLDER; //返回不合法的占位符
    }
}


void LogFormatter::setFormatFunc(){
    /*设置格式化占位符对应的格式化函数指针*/
    for(int i=0; i<this->componentList.size(); i++){
        this->formatFunc.push_back(std::bind(&FormatComponent::format, &this->componentList[i], std::placeholders::_1, std::placeholders::_2)); 
    }
    this->formatFunc.push_back([](std::ostream &out, const LogInfo &logInfo){out<<this->originChar;});
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
LogFormatter::LogFormatter(std::string format): LogFormatter()
{
    for(int i=0; i<)
    this->format = format;
    //特殊情况处理
    if(format.size()==1){
        if(format[0]=='%'){
            this->formatFlag = false;       //格式字符串不合法
            return;
        }
        if(format[0]!='%'){
            //说明是消息主体
            this->originalChar.push_back(format[0]);
            this->placeholderList.push_back(LogPlaceholder::ORIGINAL_CHAR);
            return;
        }
    }
    for(int i=0, j=1; j<=format.size(); ){
        //逻辑复杂，需要多考虑
        if(i>=format.size() || j>=format.size())    break;
        if(format[i]=='%' && i<format.size()){
            j=i+1;
            if(j>=format.size()){
                this->formatFlag = false;
                return;
            }
            else{
                if(FormatConvert::toPlaceholder(format[j])==LogPlaceholder::WRONG_PLACEHOLDER){
                    this->formatFlag = false;
                    return; 
                }
                else{
                    this->placeholderList.push_back(FormatConvert::toPlaceholder(format[j]));
                }
            }
            i=j+1;
        }
        else{
            j=i+1;
            this->originalChar.push_back(format[i]);
            i++;
        }
    }
}

/*
void LogFormatter::setFormat(std::string format){
    
}
*/

std::string LogFormatter::formatInfo(std::ostream out, LogInfo logInfo){
    //需要处理format不合法的情况，需要在调用处处理
    this->clear();
    for(int i=0; i<this->placeholderList.size(); i++){
        
    }
}

LogFormatter::~LogFormatter(){

}

void LogFormatter::clear(){
    this->out_str.clear();
    this->originalChar.clear();
    this->site=0;
}
  
