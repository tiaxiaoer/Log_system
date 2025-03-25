

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


void LogFormatter::setFormatFunc(){
    this->formatFunc.push_back(DateFormatComponent::format);
    this->formatFunc.push_back(LevelFormatComponent::format);
    this->formatFunc.push_back(FilenameFormatComponent::format);
    this->formatFunc.push_back(LineFormatComponent::format);

    this->formatFunc.push_back(ThreadIdFormatComponent::format);
    this->formatFunc.push_back(ChangeLineFormatComponent::format);
    this->formatFunc.push_back(MessageFormatComponent::format);
    this->formatFunc.push_back(TabFormatComponent::format);
    this->formatFunc.push_back(LoggerNameFormatComponent::format);
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

