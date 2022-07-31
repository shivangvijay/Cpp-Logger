/**
* @file logger.h
* @author Shivang Vijay (shivang.vijay@gmail.com)
* @version 1.0 
**/

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

#define FILE_LOG true
#define CONSOLE_LOG true

namespace Logger_Project
{
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
            std::unique_lock<std::mutex> lock(m_mutex);
            if(m_LogLevel >= LOG_LEVEL_ERROR)
            {
                if((FILE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
                {
                    m_File << "[ERROR] " << getCurrentTime() << " ";
                }

                if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
                {
                    std::cout << RED << "[ERROR] " << getCurrentTime() << " ";
                    // errorHelper(var1, var2...);
                }
                lock.unlock();
                helper(var1, var2...);
            }
        }

        // Info log
        template <typename arg, typename... args>
        void info(arg var1, args... var2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if(m_LogLevel >= LOG_LEVEL_INFO)
            {
                if((FILE_LOG))
                {
                    m_File << "[INFO] " << getCurrentTime() << " ";
                }
                if((CONSOLE_LOG))
                {
                    std::cout << MAGENTA << "[INFO] " << getCurrentTime() << " ";
                }
                lock.unlock();
                helper(var1, var2...);
            }
        }

        // Trace log
        template <typename arg, typename... args>
        void trace(arg var1, args... var2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if(m_LogLevel >= LOG_LEVEL_TRACE)
            {
                if((FILE_LOG))
                {
                    m_File << "[TRACE] " << getCurrentTime() << " ";
                }
                if((CONSOLE_LOG))
                {
                    std::cout << CYAN << "[TRACE] " << getCurrentTime() << " ";
                }
                lock.unlock();
                helper(var1, var2...);
            }
        }

        // Debug log
        template <typename arg, typename... args>
        void debug(arg var1, args... var2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if(m_LogLevel >= LOG_LEVEL_DEBUG)
            {
                if((FILE_LOG))
                {
                    m_File << "[DEBUG] " << getCurrentTime() << " ";
                }
                if((CONSOLE_LOG))
                {
                    std::cout << YELLOW << "[DEBUG] " << getCurrentTime() << " ";
                }
                lock.unlock();
                helper(var1, var2...);
            }
        }

        // log levels
        void updateLogLevel(LogLevel logLevel);
        void enableLog();   // Enable all log levels
        void disableLog(); // Disable all log levels

    private:
        // helper function
        template <typename arg, typename... args>
        void helper(arg var1, args... var2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if((FILE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
            {
                m_File << var1 << " ";
            }
            if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
            {
                std::cout << var1 << " ";
            }
            lock.unlock();
            helper(var2...);
        }

        void helper();
        Logger();
        ~Logger();    
        Logger(const Logger &obj) {}
        std::string getCurrentTime(); // timestamp
        void operator=(const Logger &obj) {}

    private:
        static Logger *m_Instance;
        std::ofstream m_File;
        LogLevel m_LogLevel;
        LogLevel m_currentLog;
        std::mutex m_mutex;
    };
}
#endif // End of _LOGGER_H_