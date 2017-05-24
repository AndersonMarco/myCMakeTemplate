#ifndef errors_h
#define errors_h
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#define MALLOC_SUCESS 0
#define MALLOC_ERROR 2
#define FILEOPEN_ERROR 3
#define FILEREAD_ERROR 4
#define FILEWRITE_ERROR 5
#define FILECLOSE_ERROR 6
#define FILESEEK_ERROR 7
#define FILETELL_ERROR 8
#define FILEOPEN_MSVC_ERROR 9
#define FILECLOSE_MSVC_ERROR 10
#define FILELENGTH64_ERROR 11
#define FILEOPEN_POSIX_ERROR 12
#define FILECLOSE_POSIX_ERROR 13
#define FILESEEKO_ERROR 14
#define FILETELLO_ERROR 15
#ifndef __func__
#define __func__ __FUNCTION__
#endif

void createMsgError(int error,const char *type,int mark , const char* functionName, const char* file);
#define checkGeneric(ret)\
    if(ret!=0){\
        createMsgError(ret,"generic error",__LINE__,__func__,__FILE__);    \
        return ret;\
    }
#define checkGenericReturnVoid(ret,codeForFreeMemory)                   \
    if(ret!=0){                                                         \
        createMsgError(ret,"generic error",__LINE__,__func__,__FILE__); \
        codeForFreeMemory();                                            \
        return;                                                         \
    }

#define checkMallocObject(ret)\
    if(ret!=MALLOC_SUCESS){\
        createMsgError(ret,"malloc object",__LINE__,__func__,__FILE__);    \
        return ret;\
    }

#define checkMalloc(ret)\
    if(ret==MALLOC_ERROR){\
        createMsgError(ret,"malloc ",__LINE__,__func__,__FILE__);    \
        return ret;\
    }

#define checkMallocReturnVoid(val, ret,codeForFreeMemory)               \
    if(val==NULL){                                                      \
        createMsgError(MALLOC_ERROR,"malloc ",__LINE__,__func__,__FILE__); \
        *ret=MALLOC_ERROR;                                              \
        codeForFreeMemory();                                            \
        return ;                                                        \
    }



#define checkReadWriteAtFile(file,retFail)                              \
    if(ferror (file)){                                                  \
        printf("Error \n type: write or read\n code: %d\n line: %d\n function: %s\n file: %s\n",ferror(file), __LINE__,__func__, __FILE__); \
        fclose(file);                                                    \
        return retFail;                                                 \
    }
#define checkFileOpen(file,retFail)                                  \
    if(file ==0x0){                                                  \
        printf("Error \n type: file open\n line: %d\n function: %s\n file: %s\n", __LINE__,__func__, __FILE__); \
        return retFail;                                                 \
    }
#ifdef __cplusplus
}
#endif

#endif

