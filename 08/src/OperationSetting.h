
#ifndef OPERATIONSETTING_FILE
#define OPERATIONSETTING_FILE

#include "InputReader.h"

#define PREFIX_CALL "cashed.call."

typedef struct{
    char* filename;
    int staticN;
    int returnN;
    Allocator callCaching;
    int returnCached;
    char* currentFunction;
}OperationSetting;

// crea la struttura Operation Settings che verrà Utilizzata in tutto il progetto per condividere impostazioni condivise
OperationSetting createOperationSetting(Input *inp);
OperationSetting createOperationSettingWithoutFile();
// de alloca gli elementi in questa struct
void freeOperationSetting(OperationSetting* operation);
void updateNameOfOperationSetting(OperationSetting* op,Input* inp);
int isCaschedCall(OperationSetting* op,char * function);
void addCaschedCall(OperationSetting* op,char * function);
char* getCashedCallLabel(char* function);
void updateFunction(OperationSetting *op,char* function);
#endif