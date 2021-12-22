#ifndef OPERATIONFLOW_FILE
#define OPERATIONFLOW_FILE

#include <string.h>
#include "Allocator.h"
#include "OperationSetting.h"
#include "StringOperation.h"



void label(char* inp,Allocator* all,OperationSetting* op);
void opGoto(char* inp,Allocator* all,OperationSetting* op);
void opIfgoto(char* inp,Allocator* all,OperationSetting* op);


#endif