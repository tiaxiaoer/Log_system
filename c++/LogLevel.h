#include <string>

#include "enum.h"

class Loglevel{
private:
    LogLevel level;
public:
    Loglevel();
    ~Loglevel();
    static std::string toString(LogLevel level);
    static LogLevel fromString(std::string level);

};