#include "logger.h"

void example1(){
    std::cout << "Logger Example 1 " << std::endl;
    Logger_Project::Logger::getInstance()->trace("Trace Log example:- ", "String:", "TestString",
    "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    Logger_Project::Logger::getInstance()->debug("Debug Log example:- ", "String", 23.8, 53, true);
    Logger_Project::Logger::getInstance()->error("Error Log example:- ", "String", 67.8, 97, true);
    Logger_Project::Logger::getInstance()->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

void example2(){

    std::cout << "Logger Example 2 " << std::endl;
    auto loggerInst = Logger_Project::Logger::getInstance();
    loggerInst->trace("Trace Log example:- ", "String:", "TestString", "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    loggerInst->debug("Debug Log example:- ", "String", 23.8, 53, true);
    loggerInst->error("Error Log example:- ", "String", 67.8, 97, true);
    loggerInst->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

void example3(){
    std::cout << "Logger Example of enable and disable" << std::endl;
    Logger_Project::Logger::getInstance()->disableLog(); //disable all logs
    Logger_Project::Logger::getInstance()->trace("Trace Log example:- ", "String:", "TestString",
    "Printing Double:-", 97.9,"Printing Int:-", 23,"Printing Bool:-", true);
    Logger_Project::Logger::getInstance()->debug("Debug Log example:- ", "String", 23.8, 53, true);
    Logger_Project::Logger::getInstance()->enableLog();  //enable all logs
    Logger_Project::Logger::getInstance()->error("Error Log example:- ", "String", 67.8, 97, true);
    Logger_Project::Logger::getInstance()->info("Info Log example:- ", "String", 45.7, 65, false);
    std::cout << "\n\n";
}

