/**
* @file logger.cpp
* @author Shivang Vijay (shivang.vijay@gmail.com)
* @version 1.0 
**/

#include "logger.h"

using namespace Logger_Project;

Logger* Logger::m_Instance = 0;

Logger::Logger()
{
   if(FILE_LOG)
   {
      this->LogFileName();
   }

   // Replace Enable log to change the log level
   m_LogLevel = ENABLE_LOG;      
}

void Logger::LogFileName()
{
   std::string prefix = "../logs/<CUSTOMENAME>_"; 
   std::string suffix = ".log";
   std::string middle = this->getCurrentTime();
   reservedFileName = prefix + middle + "_";
   logFileName = reservedFileName + std::to_string(fileCount) + suffix;
   m_File.open(logFileName.c_str(), std::ios::out|std::ios::app);
}

Logger::~Logger()
{
   if(FILE_LOG)
   {
      m_File.close();
   }
}

std::ifstream::pos_type Logger::filesize(const char* filename)
{
   std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
   return in.tellg(); 
}

Logger* Logger::getInstance()
{
   if (m_Instance == 0) 
   {
      m_Instance = new Logger();
   }
   return m_Instance;
}

void Logger::helper()
{
   std::lock_guard<std::mutex> lock(m_mutex);
   if((FILE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
   {
         m_File << std::endl;
         if(filesize(logFileName.c_str()) > FILE_SIZE_IN_MB*1000000)
         {
            m_File.close();
            fileCount++;
            logFileName = reservedFileName + std::to_string(fileCount) + ".log";
            m_File.open(logFileName.c_str(), std::ios::out|std::ios::app);
         }
   }
   if((CONSOLE_LOG) && (m_LogLevel >= LOG_LEVEL_ERROR))
   {
         std::cout << RESET << std::endl;
   }
}

// Get timeStamp in human readable form
std::string Logger::getCurrentTime()
{
   std::string currTime;
   //Current date/time based on current time
   time_t now = time(0); 

   // Convert current time to string
   currTime.assign(ctime(&now));

   // Last charactor of currentTime is "\n", so remove it
   std::string currentTime = currTime.substr(0, currTime.size()-1);
   return currentTime;
}

// log levels
void Logger::updateLogLevel(LogLevel logLevel)
{
   m_LogLevel = logLevel;
}

// Enable all log levels
void Logger::enableLog()
{
   m_LogLevel = ENABLE_LOG; 
}

// Disable all log levels
void Logger:: disableLog()
{
   m_LogLevel = DISABLE_LOG;
}