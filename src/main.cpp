#include "logger.h"

int main(){
    std::cout << "Start writing logger" << std::endl;
    Logger_Project::Logger::getInstance()->trace("Trace Log example", "Print String", "Printing DOuble", 23.0, 23, true);
}