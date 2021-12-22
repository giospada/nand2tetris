
#ifndef OPERATIONSETTING_FILE
#define OPERATIONSETTING_FILE

#include "InputReader.h"

typedef struct{
    char* filename;
    int staticN;
    int returnN;
}OperationSetting;

// crea la struttura Operation Settings che verrà Utilizzata in tutto il progetto per condividere impostazioni condivise
OperationSetting createOperationSetting(Input *inp);
// de alloca gli elementi in questa struct
void freeOperationSetting(OperationSetting* operation);
#endif