
#ifndef OPERATIONSETTING_FILE
#define OPERATIONSETTING_FILE

#include "InputReader.h"

typedef struct{
    char* filename;
    int staticN;
}OperationSetting;


OperationSetting createOperationSetting(Input *inp);
void freeOperationSetting(OperationSetting* operation);
#endif