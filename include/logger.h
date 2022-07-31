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

// set config
#define FILE_LOG true
#define CONSOLE_LOG true
#define FILE_SIZE_IN_MB 50   //for rollover
#define PREFIX_NAME "<CUSTOMIZE>"
#define SET_LOG_LEVEL 6

namespace Logger_Project
{
    typedef enum LOG_LEVEL
    {
        DISABLE_LOG = 1,
        LOG_LEVEL_ERROR = 2,
        LOG_LEVEL_TRACE = 3,
        LOG_LEVEL_DEBUG = 4,
        LOG_LEVEL_INFO = 5,
        ENABLE_LOG = 6,
    } LogLevel;

    class Logger
    {
    public:
        /**
         * @brief Get the Instance object
         * 
         * @return Logger* 
         */
        static Logger *getInstance();

        /**
         * @brief error llog
         * 
         * @tparam arg 
         * @tparam args 
         * @param var1 
         * @param var2 
         */
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

        /**
         * @brief info log
         * 
         * @tparam arg 
         * @tparam args 
         * @param var1 
         * @param var2 
         */
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

        /**
         * @brief trace log
         * 
         * @tparam arg 
         * @tparam args 
         * @param var1 
         * @param var2 
         */
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

        /**
         * @brief debug log
         * 
         * @tparam arg 
         * @tparam args 
         * @param var1 
         * @param var2 
         */
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

        /**
         * @brief update log level
         * 
         * @param logLevel 
         */
        void updateLogLevel(LogLevel logLevel);

        /**
         * @brief Enable all log levels
         * 
         */
        void enableLog();

        /**
         * @brief Disable all log levels
         * 
         */
        void disableLog();

    private:
        /**
         * @brief Helper function
         * 
         * @tparam arg 
         * @tparam args 
         * @param var1 
         * @param var2 
         */
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

        /**
         * @brief 
         * 
         */
        void helper();

        /**
         * @brief Construct a new Logger object
         * 
         */
        Logger();

        /**
         * @brief Destroy the Logger object
         * 
         */
        ~Logger();   

        /**
         * @brief Construct a new Logger object
         * 
         * @param obj 
         */
        Logger(const Logger &obj) {}

        /**
         * @brief Get the Current Time Stamp object
         * 
         * @return std::string 
         */
        std::string getCurrentTime();

        /**
         * @brief 
         * 
         * @param obj 
         */
        void operator=(const Logger &obj) {}

        /**
         * @brief to calculate filesize
         * 
         * @param filename 
         * @return std::ifstream::pos_type 
         */
        std::ifstream::pos_type filesize(const char* filename);

        /**
         * @brief 
         * 
         */
        void LogFileName();

    private:
        static Logger *m_Instance;
        std::ofstream m_File;
        LogLevel m_LogLevel;
        LogLevel m_currentLog;
        std::mutex m_mutex;
        int fileCount{1};
        std::string reservedFileName;
        std::string logFileName;
    };
}
#endif // End of _LOGGER_H_