
#include <iostream>

#include "FormatComponent.h"

void DateYearFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeYear();
}

void DateMonthFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeMonth();
}

void DateDayFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeDay();
}

void DateHourFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeHour();
}

void DateMinuteFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeMinute();
}

void DateSecondFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getTimeSecond();
}

void LevelFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << LogLevel::toString( logInfo.getLevel() );
}

void FilenameFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getFilename();
}

void LineFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getLine();
}

void ThreadIdFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getThreadId();
}

void ChangeLineFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << "\n";
}

void MessageBodyFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getMessage();
}

void TabFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << "\t";
}

void LoggerNameFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << logInfo.getLoggerId() + ' ' + logInfo.getLoggerName();
}

void ModFormatComponent::format(std::ostream &out, const LogInfo &logInfo)
{
    out << "%";
}

