#ifndef INSTRUCTIONPROCESSOR_FILE
#define INSTRUCTIONPROCESSOR_FILE


#include <string.h>
#include "Allocator.h"
#include "StringOperation.h"
#include "OperationAritmeticBool.h"
#include "OperationMemory.h"
#include "OperationFlow.h"
#include "OperationSubroutine.h"


Allocator initOperation();
Allocator processLine(char* line,OperationSetting* op);

#endif
