#include "OutProcessor.h"




char* fileName(Input* inp){
    char* outName;
    {
        outName=malloc(strlen(inp->fileName)+2);
        int point=0;
        for (int i = 0; i < strlen(inp->fileName); i++)
        {
            if(inp->fileName[i]=='.'){
                point=i;
            }
        }
        for(int i=0;i<=point;i++){
            outName[i]=inp->fileName[i];
        }
        char extention[]="asm";
        for(int i=0;i<strlen(extention)+1;i++){
            outName[point+i+1]=extention[i];
        }
    }
    return outName;
}
FILE* openDir(InputDir* inp){
    char* temp=basename(inp->dirName);
    char* outName=strConcat(temp,".asm");

#ifdef DBG
        printf("%s\n",outName);
#endif
#ifdef DBG
    FILE *outFile =stdout; 
#else
    FILE *outFile = fopen(outName, "w");
#endif
    free(outName);

    return outFile;
}

FILE* openFile(Input* inp){
    char* outName=fileName(inp);
#ifdef DBG
        printf("%s\n",outName);
#endif
#ifdef DBG
    FILE *outFile =stdout; 
#else
    FILE *outFile = fopen(outName, "w");
#endif
    return outFile;

}

void writeAllocator(FILE* f,Allocator* all){
    for(int i=0;i<all->len;i++){
        fputs((char*)getFromAllocator(all,i),f);
        fputs("\n",f);
    }
}