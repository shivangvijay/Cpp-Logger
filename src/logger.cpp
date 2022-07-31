#include "logger.h"

using namespace Logger_Project;

Logger* Logger::m_Instance = 0;

std::string LogMidName()
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

Logger::Logger()
{
   //Log file name
   std::string prefix = "../logs/NAME_";
   std::string suffix = ".log";
   std::string middleDiff = LogMidName();
   const std::string logFileName = prefix + middleDiff + suffix;

   m_File.open(logFileName.c_str(), std::ios::out|std::ios::app);

   m_LogLevel = ENABLE_LOG;   
}

Logger::~Logger()
{}

Logger* Logger::getInstance()
{
   if (m_Instance == 0) 
   {
      m_Instance = new Logger();
   }
   return m_Instance;
}


void Logger::logIntoFile(std::string& data)
{
   m_File << getCurrentTime() << "  " << data << std::endl;
}

void Logger::logOnConsole(std::string& data)
{
   if(m_currentLog==LOG_LEVEL_ERROR)
   {
      std::cout << BOLDRED <<getCurrentTime() << "  " << data << std::endl << RESET;
   }
   else if(m_currentLog==LOG_LEVEL_INFO)
   {
      std::cout << GREEN << getCurrentTime() << "  " <<  data << std::endl << RESET;
   }
   else if(m_currentLog==LOG_LEVEL_TRACE)
   {
      std::cout << MAGENTA << getCurrentTime() << "  " <<  data << std::endl << RESET;
   }
   else if(m_currentLog==LOG_LEVEL_DEBUG)
   {
      std::cout << YELLOW << getCurrentTime() << "  " <<  data << std::endl << RESET;
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