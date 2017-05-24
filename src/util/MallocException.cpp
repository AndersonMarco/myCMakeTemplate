#include "MallocException.hpp"
MallocException::MallocException(int line, const char * function ,const char * file ){
    this->file=file;
    this->function=function;
    this->line=line;
}
const char* MallocException::what() const throw(){
    const char *ret=(const char *)malloc(sizeof(char)*1024);
    sprintf((char *)ret,"MalloException at: line %d, function \'%s\', file \'%s\'",this->line, (const char *)this->function,(const char *)this->file);
    return ret;
}
