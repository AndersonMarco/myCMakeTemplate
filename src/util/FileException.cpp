#include "FileException.hpp"
FileException::FileException(int errorCode,int line, const char * function ,const char * file ){
    this->file=file;
    this->function=function;
    this->line=line;
    this->errorCode=errorCode;
}
const char* FileException::what() const throw(){
    const char *ret=(const char *)malloc(sizeof(char)*512);
    sprintf((char *)ret,"FileException at: code %d, line %d, function \'%s\', file \'%s\'",this->errorCode,this->line, (char *)this->function,(char*)this->file);
    return ret;
}
