#ifndef STRINGOPERATION_FILE

#define STRINGOPERATION_FILE

#include <stdlib.h>
#include <string.h>
#include "StringOperation.h"

int toInt(int from,char* s);
char* intToString(int from);
int strFirstSub(char* s1,char* s2);
char* copyString(char* s1);
char* strAppendInt(char* str,int i);
char* getLabel(char *line, int from);
char* strConcat(char* s1,char* s2);
#endif