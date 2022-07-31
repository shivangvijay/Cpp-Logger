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
#define FILE_LOG false
#define CONSOLE_LOG true

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

        // Error log
        template <typename arg, typename... args>
        void error(arg var1, args... var2)
        {
            if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
            {
                std::cout << RED << "[ERROR] " << getCurrentTime() << " ";
                errorHelper(var1, var2...);
            }
        }

        template <typename arg, typename... args>
        void errorHelper(arg var1, args... var2)
        {
            std::cout << var1 << " ";
            errorHelper(var2...);
        }

        void errorHelper()
        {
            std::cout << RESET << std::endl;
        }

        // Info log
        template <typename arg, typename... args>
        void info(arg var1, args... var2)
        {
            if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_INFO))
            {
                std::cout << MAGENTA << "[INFO] " << getCurrentTime() << " ";
                infoHelper(var1, var2...);
            }
        }

        template <typename arg, typename... args>
        void infoHelper(arg var1, args... var2)
        {
            std::cout << var1 << " ";
            infoHelper(var2...);
        }

        void infoHelper()
        {
            std::cout << RESET << std::endl;
        }

        // Trace log
        template <typename arg, typename... args>
        void trace(arg var1, args... var2)
        {
            if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_TRACE))
            {
                std::cout << CYAN << "[TRACE] " << getCurrentTime() << " ";
                traceHelper(var1, var2...);
            }
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
        template <typename arg, typename... args>
        void debug(arg var1, args... var2)
        {
            if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_DEBUG))
            {
                std::cout << YELLOW << "[DEBUG] " << getCurrentTime() << " ";
                debugHelper(var1, var2...);
            }
        }

        template <typename arg, typename... args>
        void debugHelper(arg var1, args... var2)
        {
            std::cout << var1 << " ";
            debugHelper(var2...);
        }

        void debugHelper()
        {
            std::cout << RESET << std::endl;
        }

        // log levels
        void updateLogLevel(LogLevel logLevel);
        void enableLog();   // Enable all log levels
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