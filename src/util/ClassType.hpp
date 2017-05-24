#include "stdlib.h"
#include "stdint.h"
#ifndef util__ClassType_h
#define util__ClassType_h
class ClassType{
    virtual uint32_t getObjectClass()=0;
};
#endif
