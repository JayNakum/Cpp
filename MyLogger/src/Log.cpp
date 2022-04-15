#include <iostream>

class Log
{
public:
    // const int logLevelError = 0;
    // const int logLevelWarning = 1;
    // const int logLevelInfo = 2;

    enum Level : unsigned char
    {
        LevelError = 0,
        LevelWarning,
        LevelInfo
    };

private:
    Level m_logLevel;

public:
    // Log() = delete; // to delete the "default constructor"

    Log()
    {
        m_logLevel = LevelInfo;
    }

    Log(Level level)
    {
        m_logLevel = level;
    }

    ~Log()
    {
        std::cout << "Logger Destroyed" << std::endl;
    }

public:
    void setLevel(Level level)
    {
        m_logLevel = level;
    }

    void error(const char *msg)
    {
        if (m_logLevel >= LevelError)
            std::cout << "[ERROR]: " << msg << std::endl;
    }

    void warning(const char *msg)
    {
        if (m_logLevel >= LevelWarning)
            std::cout << "[WARNING]: " << msg << std::endl;
    }

    void info(const char *msg)
    {
        if (m_logLevel >= LevelInfo)
            std::cout << "[INFO]: " << msg << std::endl;
    }
};

int main()
{
    Log log(Log::LevelWarning);
    log.info("Hello!");
    log.setLevel(Log::LevelError);
    log.warning("Hello!");
    // log.~Log(); // calling destructor explicitly
    log.error("Hello!");
}
