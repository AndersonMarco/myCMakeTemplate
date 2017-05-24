#ifndef  util__FileException_h
#define  util__FileException_h
#include <stdint.h>
#include "errors.h"
#include <string.h>
#include <stdlib.h>
#include <exception>

using namespace std;
class FileException: public exception{
private:
    int errorCode;
    int line;
    const char* file;
    const char* function;

public:
    FileException(int errorCode,int line, const char * function ,const char * file );
    const char * what() const throw ();
};
#define throwFileException(errorCode) if(errorCode!=0)throw FileException(errorCode,__LINE__,__func__,__FILE__);

#endif
