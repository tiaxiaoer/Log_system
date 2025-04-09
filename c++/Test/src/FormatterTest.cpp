#include <gtest/gtest.h>
#include <sstream>
#include "c++/include/LogFormatter.h" // 包含待测函数的头文件

TEST(FormatInfoTest, BasicFormatting) {
    std::ostringstream oss;
    LogInfo info;
    info.message = "Test message";
    info.level = "INFO";
    info.timestamp = "2023-01-01 12:00:00";
    
    formatInfo(oss, info);
    
    std::string expected = "[2023-01-01 12:00:00] [INFO] Test message";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FormatInfoTest, EmptyMessage) {
    std::ostringstream oss;
    LogInfo info;
    info.message = "";
    info.level = "WARNING";
    info.timestamp = "2023-01-01 12:00:00";
    
    formatInfo(oss, info);
    
    std::string expected = "[2023-01-01 12:00:00] [WARNING] ";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FormatInfoTest, SpecialCharacters) {
    std::ostringstream oss;
    LogInfo info;
    info.message = "Error: 100% & $#@!";
    info.level = "ERROR";
    info.timestamp = "2023-01-01 12:00:00";
    
    formatInfo(oss, info);
    
    std::string expected = "[2023-01-01 12:00:00] [ERROR] Error: 100% & $#@!";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FormatInfoTest, LongMessage) {
    std::ostringstream oss;
    LogInfo info;
    info.message = std::string(1000, 'x'); // 1000个字符的长消息
    info.level = "DEBUG";
    info.timestamp = "2023-01-01 12:00:00";
    
    formatInfo(oss, info);
    
    std::string expected = "[2023-01-01 12:00:00] [DEBUG] " + std::string(1000, 'x');
    EXPECT_EQ(oss.str(), expected);
}

TEST(FormatInfoTest, MissingFields) {
    std::ostringstream oss;
    LogInfo info;
    info.message = "Test";
    info.level = ""; // 空level
    info.timestamp = ""; // 空timestamp
    
    formatInfo(oss, info);
    
    std::string expected = "[] [] Test";
    EXPECT_EQ(oss.str(), expected);
}
/*
解释：

BasicFormatting 测试基本功能，验证正常输入下的格式化输出
EmptyMessage 测试空消息的情况，验证边界条件处理
SpecialCharacters 测试特殊字符处理，验证转义和特殊字符支持
LongMessage 测试长消息处理，验证性能和大数据量处理
MissingFields 测试缺失字段的情况，验证空字段处理逻辑
这些测试用例覆盖了：

正常输入场景
边界条件（空消息）
特殊字符处理
大数据量处理
异常输入（缺失字段）
使用Google Test框架，通过EXPECT_EQ断言验证输出是否符合预期。每个测试用例都使用独立的ostringstream来捕获输出，避免测试间相互影响。

<|EOUT|>
*/