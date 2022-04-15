#include <iostream>

class Log
{
public:
    const int logLevelError = 0;
    const int logLevelWarning = 1;
    const int logLevelInfo = 2;

private:
    int m_logLevel = logLevelInfo;

public:
    void setLevel(int level)
    {
        m_logLevel = level;
    }

    void error(const char *msg)
    {
        if (m_logLevel >= logLevelError)
            std::cout << "[ERROR]: " << msg << std::endl;
    }

    void warning(const char *msg)
    {
        if (m_logLevel >= logLevelWarning)
            std::cout << "[WARNING]: " << msg << std::endl;
    }

    void info(const char *msg)
    {
        if (m_logLevel >= logLevelInfo)
            std::cout << "[INFO]: " << msg << std::endl;
    }
};

void test()
{
    Log log;
    log.setLevel(log.logLevelWarning);
    log.warning("Hello");
}