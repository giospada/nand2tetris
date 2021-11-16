#ifndef OPERATIONARITHMETICBOOL_FILE
#define OPERATIONARITHMETICBOOL_FILE

#include <string.h>
#include "Allocator.h"
#include "OperationSetting.h"
#include "StringOperation.h"



void add(char* inp,Allocator* all,OperationSetting* op);
void sub(char* inp,Allocator* all,OperationSetting* op);

void and(char* inp,Allocator* all,OperationSetting* op);
void or(char* inp,Allocator* all,OperationSetting* op);
void not(char* inp,Allocator* all,OperationSetting* op);

void neg(char* inp,Allocator* all,OperationSetting* op);
void eq(char* inp,Allocator* all,OperationSetting* op);
void gt(char* inp,Allocator* all,OperationSetting* op);
void lt(char* inp,Allocator* all,OperationSetting* op);


#endif