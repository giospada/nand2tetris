#include "OperationMemory.h"


typedef struct{
    int f;
    int s;
}pair;

char *parameter[] = {
    "static", "local", "argument", "constant"};


pair getOperation(char* line){
    int index = -1;
    int minPos = 1e5;
    for (int i = 0; i < 4; i++)
    {
        int ret = strFirstSub(line, parameter[i]);
        if (minPos > ret && ret != -1)
        {
            minPos = ret;
            index = i;
        }
    }
    pair s = {.f = index, .s = minPos};
    return s;
}

void push(char *line, Allocator *all)
{
    int index;
    int minPos;
    {
        pair temp = getOperation(line);
        index = temp.f;
        minPos = temp.s;
    }
    int parametro = toInt(minPos + strlen(parameter[index]), line);
    
    addElement(all, strAppendInt(copyString("@"),parametro));
    addElement(all, copyString("D=A"));

    switch (index)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
    {
        addElement(all, copyString("@ARG"));
        addElement(all, copyString("A=D+M"));
        addElement(all, copyString("D=A"));
    }
    break;
    case 3:
        break;
    }
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M"));
    addElement(all, copyString("M=D"));
    addElement(all, copyString("@SP"));
    addElement(all, copyString("M=M+1"));
}

void pop(char *line, Allocator *all)
{
    int index;
    {
        pair temp = getOperation(line);
        index = temp.f;
    }
    switch (index)
    {
    case 0:
        addElement(all, copyString("@LCL"));
        break;
    case 1:
        addElement(all, copyString("@LCL"));
        break;
    case 2:
        addElement(all, copyString("@LCL"));
        break;
    case 3:
        addElement(all, copyString("@THIS"));
        break;
    }
}