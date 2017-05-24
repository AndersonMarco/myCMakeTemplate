#include "errors.h"
#ifdef __cplusplus
extern "C" {
#endif

void createMsgError(int error,const char *type,int mark , const char* functionName, const char* file){
    printf("Error  \n type: %s \n code: %d\n line: %d\n function: %s\n file: %s\n",type , error, mark,functionName, file); \
}
    
#ifdef __cplusplus
}
#endif
