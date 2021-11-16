#ifndef OPERATIONARITHMETICBOOL_FILE
#define OPERATIONARITHMETICBOOL_FILE

#include <string.h>
#include "Allocator.h"
#include "StringOperation.h"



void add(char* inp,Allocator* all);
void sub(char* inp,Allocator* all);

void and(char* inp,Allocator* all);
void or(char* inp,Allocator* all);
void not(char* inp,Allocator* all);

void neg(char* inp,Allocator* all);
void eq(char* inp,Allocator* all);
void gt(char* inp,Allocator* all);
void lt(char* inp,Allocator* all);


#endif