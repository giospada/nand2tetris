#ifndef OPERATIONSUBROUTINE_FILE
#define OPERATIONSUBROUTINE_FILE

#include <string.h>
#include "Allocator.h"
#include "OperationSetting.h"
#include "StringOperation.h"



void opFunction(char* inp,Allocator* all,OperationSetting* op);
void opCall(char* inp,Allocator* all,OperationSetting* op);
void opReturn(char* inp,Allocator* all,OperationSetting* op);

#endif