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

Step 1: – Add #include <logger.h>
Step 2:- Use it. 

Refer examples.cpp to explore more way to use.





