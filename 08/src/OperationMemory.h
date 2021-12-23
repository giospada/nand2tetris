#ifndef OPERATIOMORY_FILE

#define OPERATIOMORY_FILE

#include "Allocator.h"
#include "StringOperation.h"
#include "OperationSetting.h"
#include <assert.h>
#include <stdlib.h>


void push(char* line,Allocator* all,OperationSetting* op);
void pop(char* line,Allocator* all,OperationSetting* op);

#endif