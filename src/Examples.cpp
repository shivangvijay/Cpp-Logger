/**
* @file Examples.cpp
* @author Shivang Vijay (shivang.vijay@gmail.com)
* @version 1.0 
**/

#include "logger.h"

void example1(){
    Logger_Project::Logger::getInstance()->info("Logger Example 1");
    Logger_Project::Logger::getInstance()->trace("Trace Log example:- ", "String:", "TestString",
    "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    Logger_Project::Logger::getInstance()->debug("Debug Log example:- ", "String", 23.8, 53, true);
    Logger_Project::Logger::getInstance()->error("Error Log example:- ", "String", 67.8, 97, true);
    Logger_Project::Logger::getInstance()->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

void example2(){
    Logger_Project::Logger::getInstance()->info("Logger Example 2");
    auto loggerInst = Logger_Project::Logger::getInstance();
    loggerInst->trace("Trace Log example:- ", "String:", "TestString", "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    loggerInst->debug("Debug Log example:- ", "String", 23.8, 53, true);
    loggerInst->error("Error Log example:- ", "String", 67.8, 97, true);
    loggerInst->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

void example3(){
    Logger_Project::Logger::getInstance()->info("Logger Example of enable and disable");
    Logger_Project::Logger::getInstance()->disableLog(); //disable all logs here
    Logger_Project::Logger::getInstance()->trace("Trace Log example:- ", "String:", "TestString",
    "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    Logger_Project::Logger::getInstance()->debug("Debug Log example:- ", "String", 23.8, 53, true);
    Logger_Project::Logger::getInstance()->enableLog();  //enable all logs here
    Logger_Project::Logger::getInstance()->error("Error Log example:- ", "String", 67.8, 97, true);
    Logger_Project::Logger::getInstance()->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

