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


OperationSetting createOperationSettingWithoutFile(){
    OperationSetting op;
    op.staticN=0;
    op.returnN=0;
    op.filename=NULL;
    op.returnCached=0;
    op.callCaching=createAllocator();
    op.currentFunction=NULL;
    return op;
}

void updateFunction(OperationSetting *op,char* function){
    if(op->currentFunction!=NULL){
        free(op->currentFunction);
    }
    op->currentFunction=copyString(function);
}

void updateNameOfOperationSetting(OperationSetting* op,Input* inp){
    if(op->filename!=NULL){
        free(op->filename);
    }
    op->filename=fileBaseName(inp);
}

OperationSetting createOperationSetting(Input* inp){
    OperationSetting op=createOperationSettingWithoutFile();
    op.filename=fileBaseName(inp);
    return op;
}
void freeOperationSetting(OperationSetting* operation){
    free(operation->filename);
    freeAllocatorAndElements(&operation->callCaching);
    free(operation->currentFunction);
}

int isCaschedCall(OperationSetting* op,char * function){
    
    char * toCheck=getCashedCallLabel(function);
    for(int i=0;i<op->callCaching.len;i++){
        char* current=getFromAllocator(&op->callCaching,i);
        if(0==strcmp(current,toCheck)){
            free(toCheck);
            return 1;
        }
    }
    free(toCheck);
    return 0;
}
void addCaschedCall(OperationSetting* op,char * function){
    addElement(&op->callCaching,getCashedCallLabel(function));
}
char* getCashedCallLabel(char* function){
    char * toSearch=strConcat(PREFIX_CALL,function);
    return toSearch;
}