#ifndef  util__MallocException_h
#define  util__MallocException_h
#include <stdint.h>
#include "errors.h"
#include <string.h>
#include <stdlib.h>
#include <exception>
using namespace std;
class MallocException: public exception {
private:
    int line;
    const char* file;
    const char* function;

public:
    MallocException(int line, const char * function ,const char * file );
    const char * what() const throw ();
};
#define throwMallocException(mem) if(mem==0x0)throw MallocException(__LINE__,__func__,__FILE__);

#endif
