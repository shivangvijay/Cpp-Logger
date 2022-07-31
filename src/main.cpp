/**
* @file main.cpp
* @author Shivang Vijay (shivang.vijay@gmail.com)
* @version 1.0 
**/

#include "Examples.cpp"

int main(){
    auto loggerInst = Logger_Project::Logger::getInstance();
    loggerInst->info("You can put any number of argument of any type in logger functions");
    loggerInst->info("You can check examples in Examples.cpp");
    // example1();
    // example2();
    // example3();
}