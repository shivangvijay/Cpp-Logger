#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include "config.h"

namespace Logger_Project
{
#define FILE_LOG_TEST false
#define CONSOLE_TEST true

#define LOG_ERROR(x) Logger::getInstance()->error(x)
#define LOG_INFO(x) Logger::getInstance()->info(x)
#define LOG_TRACE(x) Logger::getInstance()->trace(x)
#define LOG_DEBUG(x) Logger::getInstance()->debug(x)

    typedef enum LOG_LEVEL
    {
        DISABLE_LOG = 1,
        LOG_LEVEL_ERROR = 2,
        LOG_LEVEL_INFO = 3,
        LOG_LEVEL_TRACE = 4,
        LOG_LEVEL_DEBUG = 5,
        ENABLE_LOG = 6,
    } LogLevel;

    class Logger
    {
    public:
        static Logger *getInstance();

        // Error Log

        void error(const char *text);
        void error(std::string &text);
        void error(std::ostringstream &stream);

        // Info Log
        void info(const char *text);
        void info(std::string &text);
        void info(std::ostringstream &stream);

        // Trace log
        template <typename arg, typename... args>
        void trace(arg var1, args... var2)
        {
            std::cout << RED << "[TRACE] " << getCurrentTime() << " ";
            traceHelper(var1, var2...);
        }

        template <typename arg, typename... args>
        void traceHelper(arg var1, args... var2)
        {
            std::cout << var1 << " ";
            traceHelper(var2...);
        }

        void traceHelper()
        {
            std::cout << RESET << std::endl;
        }


        // Debug log
        void debug(const char *text);
        void debug(std::string &text);
        void debug(std::ostringstream &stream);

        // log levels
        void updateLogLevel(LogLevel logLevel);
        void enaleLog();   // Enable all log levels
        void disableLog(); // Disable all log levels

        std::string getCurrentTime();

    protected:
        Logger();
        ~Logger();

        void lock();
        void unlock();

    private:
        void logIntoFile(std::string &data);
        void logOnConsole(std::string &data);
        Logger(const Logger &obj) {}
        void operator=(const Logger &obj) {}

    private:
        static Logger *m_Instance;
        std::ofstream m_File;

        LogLevel m_LogLevel;
        LogLevel m_currentLog;
    };

}

#endif // End of _LOGGER_H_
