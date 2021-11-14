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
        char extention[]="hack";
        for(int i=0;i<strlen(extention)+1;i++){
            outName[point+i+1]=extention[i];
        }
    }
    return outName;
}
void writeAllToFile(Input* inp,SymbolicTable* st){
    char* outName=fileName(inp);
#ifdef DBG
        printf("%s\n",outName);
#endif
#ifdef DBG
    FILE *outFile =stdout; 
#else
    FILE *outFile = fopen(outName, "w");
#endif
    for(int i=0;i<inp->input.len;i++){
        char* line=getFromAllocator(&inp->input,i);
        HackInst hack=lineToHack(line,st);
        if(hack.valid==0){
            for (int i = 15; i >=0; i--)
                fputc( hack.bit[i],outFile);
            fputc('\n',outFile);
        }
    }
    free(outName);
    fclose(outFile);
}