# C++ Logger
C++ Logger designed to be as simple to use, easy to customize and very use full in C++ code base.

## Suported platforms:
#### Developements and tests are done under the following OSs :
- Ubuntu 14.04, 16.04, 18.04 and 20.04
- Windows 10
- Linux, FreeBSD, OpenBSD, Solaris, AIX
- macOS 

## Features:- 
- Simple Integration.
- Designed by using ***singleton design pattern*** for easy to use.
- Created using ***variadic template*** so the user can any number of argument and any type of argument for all the log levels or Severity.
- Easily Customizable and Flexible. 
- Custom formatting. 
- Multi/Single threaded loggers. 
- Rollover Mechanism, Uses can defined te file size, after which the new file generated with same name with +1 count number.
- Console logging (colors supported) and File logging with human readble timestamp.
- Log filtering - log levels can be modified in runtime as well as in compile time.
- Very Fast, Small and Simple Logger.


## Install

``$ git clone https://github.com/shivangv6/Logger.git `` <br />
``$ cd Logger && mkdir build && cd build`` <br />
``$ cmake .. `` <br />
``$ make`` <br />


# Usage

Step 1: – Add #include <logger.h> <br />
Step 2:- Use it. 

![alt text](https://github.com/shivangv6/Logger/blob/main/images/Example.png?raw=true)

Output:- 

![alt text](https://github.com/shivangv6/Logger/blob/main/images/output_example.png?raw=true)

Refer examples.cpp to explore more way to use.

## Customize

Many things are customize through macro function in logger.h file.

![alt text](https://github.com/shivangv6/Logger/blob/main/images/config.png?raw=true)

1. FILE LOG:- If required make true, otherwise false
2. CONSOLE LOG:- If required make true, otherwise false
3. Rollover:- File size (in MB) after which the new file generated with same name with +1 count number
4. Prefix of File name.
5. Log Levels
    - DISABLE_LOG = 1,
    - LOG_LEVEL_ERROR = 2,
    - LOG_LEVEL_TRACE = 3,
    - LOG_LEVEL_DEBUG = 4,
    - LOG_LEVEL_INFO = 5,
    - ENABLE_LOG = 6.
  
Currently I added only 4 levels (ERROR, TRACE, DEBUG, INFO) but other levels or severity can be added easily. 

# Contribution

## GitHub

Please fill bug reports and feature requests here: https://github.com/shivangvijay/Logger/issues <br />
Fork the repository, make some changes and submit them with pull-request 

## Contact
Email ID:- shivangvijay@gmail.com, I will answer any questions and requests.





