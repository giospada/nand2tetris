#include "OperationSetting.h"

char* fileBaseName(Input* inp){
    char* outName;
    {
        int end=0,start=0;
        for (int i = 0; i < strlen(inp->fileName); i++)
        {
            if(inp->fileName[i]=='.'){
                end=i+1;
            }
            if(inp->fileName[i]=='/' || inp->fileName[i]=='\\'){
                start=i+1;
            }
        }
        outName=malloc(sizeof(char)*(end-start+2));
        for(int i=start;i<end;i++){
            outName[i-start]=inp->fileName[i];
        }
        outName[end-start]='\0';
    }
    return outName;
}



OperationSetting createOperationSetting(Input* inp){
    OperationSetting op;
    op.staticN=0;
    op.filename=fileBaseName(inp);
    return op;
}
void freeOperationSetting(OperationSetting* operation){
    free(operation->filename);
}