#include "OperationMemory.h"

typedef struct{
    int f;
    int s;
}pair;

#define NUM_PAR 8
char *parameter[] = {
    "local", "argument", "this","that","static", "constant","temp","pointer"};

char *parToAInst[] = {"LCL","ARG","THIS","THAT"};



pair getOperation(char* line){
    int index = -1;
    int minPos = 1e5;
    for (int i = 0; i < NUM_PAR; i++)
    {
        int ret = strFirstSub(line, parameter[i]);
        if (minPos > ret && ret != -1)
        {
            minPos = ret;
            index = i;
        }
    }
    if(index==-1){
        printf("error: %s \n",line);
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
    switch (index)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    {
        addElement(all, strConcat("@", parToAInst[index]));
        //si può migliorare
        addElement(all, copyString("D=M"));
        addElement(all, strAppendInt("@", parametro));
        addElement(all, copyString("A=D+A"));
        addElement(all, copyString("D=M"));
    }
    break;
    case 4:
    {
        char * c=strConcat("@", op->filename);
        addElement(all, strAppendInt(c, parametro));
        addElement(all, copyString("D=M"));
        free(c);
    }
    break;
    case 5:
    {
        addElement(all,strAppendInt("@",parametro));
        addElement(all,copyString("D=A"));
    }
    break;
    case 6:
    {
        addElement(all,strAppendInt("@",5+parametro));
        addElement(all,copyString("D=M"));
    }
    break;
    case 7:
    {
        if(parametro==0){
            addElement(all,copyString("@THIS"));
        }else{
            addElement(all,copyString("@THAT"));
        }
        addElement(all,copyString("D=M"));
    }
    break;
    }
    addElement(all, copyString("@SP"));
    addElement(all, copyString("M=M+1"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=D"));
}


void popToD(Allocator* all){
    addElement(all,copyString("@SP"));
    addElement(all,copyString("AM=M-1"));
    addElement(all,copyString("D=M"));
}

void pop(char* line,Allocator* all,OperationSetting* op)
{
    
    int index;
    int minPos;
    {
        pair temp = getOperation(line);
        index = temp.f;
        minPos = temp.s;
    }
    int parametro = toInt(minPos + strlen(parameter[index]), line);
    switch (index)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    {
        addElement(all, strConcat("@", parToAInst[index]));
        addElement(all, copyString("D=M"));
        addElement(all, strAppendInt("@", parametro));
        addElement(all, copyString("D=D+A"));
        addElement(all, copyString("@R13"));
        addElement(all, copyString("M=D"));
        popToD(all);
        addElement(all, copyString("@R13"));
        addElement(all, copyString("A=M"));
    }
    break;
    case 4:
    {
        popToD(all);
        char * c=strConcat("@", op->filename);
        addElement(all, strAppendInt(c, parametro));
        free(c);
    }
    break;
    case 6:
    {
        popToD(all);
        addElement(all,strAppendInt("@",5+parametro));
    }
    break;
    case 7:
    {
        popToD(all);
        if(parametro==0){
            addElement(all,copyString("@THIS"));
        }else{
            addElement(all,copyString("@THAT"));
        }
    }
    break;
    }
    addElement(all,copyString("M=D"));
}


/*

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

    if (index == 0)
    {   
        char* temp=strConcat("@", op->filename);
        addElement(all, strAppendInt(temp, parametro));
        addElement(all, copyString("D=M"));
        free(temp);
    }
    else if(index == 7)
    {
        if(parametro==0){
            addElement(all,copyString("@THIS"));
        }else{
            addElement(all,copyString("@THAT"));
        }
        addElement(all,copyString("D=M"));

    }
    else
    {
        addElement(all, strAppendInt("@", parametro));
        addElement(all, copyString("D=A"));
        if (index == 6)
        {
            addElement(all, copyString("@5"));
            addElement(all, copyString("A=D+A"));
            addElement(all, copyString("D=M"));
        }
        else if (index != 3)
        {
            if (index == 1)
                addElement(all, copyString("@LCL"));
            else if (index == 2)
                addElement(all, copyString("@ARG"));
            else if (index == 4)
                addElement(all, copyString("@THIS"));
            else if (index == 5)
                addElement(all, copyString("@THAT"));

            addElement(all, copyString("A=D+M"));
            addElement(all, copyString("D=M"));
        }
    }
    //mette il valore di D nello stack e lo incrementa
    addElement(all,copyString("@SP"));
    addElement(all,copyString("M=M+1"));
    addElement(all,copyString("A=M-1"));
    addElement(all,copyString("M=D"));
}

void popStackToD(Allocator *all)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("AM=M-1"));
    addElement(all, copyString("D=M"));
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

    if (index == 0)
    {
        popStackToD(all);
        char* t=strConcat("@", op->filename);
        addElement(all, strAppendInt(t, parametro));
        addElement(all, copyString("M=D"));
        free(t);
    }
    else if (index == 7)
    {
        popStackToD(all);
        if(parametro==0){
            addElement(all,copyString("@THIS"));
        }else{
            addElement(all,copyString("@THAT"));
        }
        addElement(all,copyString("M=D"));
    }
    else
    {
        if (index == 6)
        {
            addElement(all, copyString("@5"));
            addElement(all, copyString("D=A"));
        }
        else
        {
            if (index == 1)
                addElement(all, copyString("@LCL"));
            else if (index == 2)
                addElement(all, copyString("@ARG"));
            else if (index == 4)
                addElement(all, copyString("@THIS"));
            else if (index == 5)
                addElement(all, copyString("@THAT"));
            addElement(all, copyString("D=M"));
        }
        addElement(all, strAppendInt("@", parametro));

        addElement(all, copyString("D=D+A"));
        addElement(all, copyString("@R13"));
        addElement(all, copyString("M=D"));
        popStackToD(all);
        addElement(all, copyString("@R13"));
        addElement(all, copyString("A=M"));
        addElement(all, copyString("M=D"));
    }
}
*/