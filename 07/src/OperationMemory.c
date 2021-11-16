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

void push(char* line,Allocator* all,OperationSetting* op)
{
    int index;
    int minPos;
    {
        pair temp = getOperation(line);
        index = temp.f;
        minPos = temp.s;
    }
    int parametro = toInt(minPos + strlen(parameter[index]), line);
    if (index != 0)
    {
        addElement(all, strAppendInt(copyString("@"), parametro));
        addElement(all, copyString("D=A"));
    }

    if (index != 3)
    {
        switch (index)
        {
        case 0:
            addElement(all, strAppendInt(strcat(copyString("@"), op->filename), parametro));
            addElement(all, copyString("D=M"));
            break;
        case 1:
            addElement(all, copyString("todo"));
            break;
        case 2:
            addElement(all, copyString("todo"));
            break;
        }
        if (index != 0)
        {
            addElement(all, copyString("A=D+M"));
            addElement(all, copyString("D=A"));
        }
    }
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M"));
    addElement(all, copyString("M=D"));
    addElement(all, copyString("@SP"));
    addElement(all, copyString("M=M+1"));
}

void pop(char *line, Allocator *all, OperationSetting *op)
{
    int index, minPos;
    {
        pair temp = getOperation(line);
        index = temp.f;
        minPos = temp.s;
    }
    int parametro = toInt(minPos + strlen(parameter[index]), line);

    addElement(all,copyString("@SP"));
    addElement(all,copyString("M=M-1"));
    addElement(all,copyString("A=M"));
    addElement(all,copyString("D=M"));
    switch (index)
    {
    case 0:
    {
        addElement(all, strAppendInt(strcat(copyString("@"), op->filename), parametro));
        addElement(all,copyString("M=D"));
    }
    break;
    case 1:
        addElement(all, copyString("todo"));
        break;
    case 2:
        addElement(all, copyString("todo"));
        break;
    }
}