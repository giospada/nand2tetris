#include "InstructionProcessor.h"


#define NINST 18

typedef struct{
    char* key;
    void (*value)(char*,Allocator*,OperationSetting* op);
}KeyVal;



Allocator initOperation(){
    Allocator all=createAllocator();
    addElement(&all,copyString("@256"));
    addElement(&all,copyString("D=A"));
    addElement(&all,copyString("@SP"));
    addElement(&all,copyString("M=D"));
    return all;
}



void temp(char* c,Allocator* all,OperationSetting* op){
    addElement(all,copyString("tmp"));
}

void comment(char* c,Allocator* all,OperationSetting* op){}

KeyVal keys[]={
    {.key="add",.value=&add},
    {.key="sub",.value=&sub},
    {.key="neg",.value=&neg},
    {.key="eq",.value=&eq},
    {.key="gt",.value=&gt},
    {.key="lt",.value=&lt},
    {.key="and",.value=&and},
    {.key="or",.value=&or},
    {.key="not",.value=&not},
    {.key="push",.value=&push},
    {.key="pop",.value=&pop},
    {.key="label",.value=&label},
    {.key="goto",.value=&opGoto},
    {.key="if-goto",.value=&opIfgoto},
    {.key="function",.value=&temp},
    {.key="call",.value=&temp},
    {.key="return",.value=&temp},
    {.key="//",.value=&comment}
};



Allocator processLine(char *line,OperationSetting* op)
{
    Allocator out = createAllocator();
    int lenLine = strlen(line);
    int index = -1;
    {
        int minPos = 1e5;
        for (int j = 0; j < NINST; j++)
        {
            KeyVal current = keys[j];
            int temp=strFirstSub(line,current.key);
            if(temp<minPos && temp!=-1){
                index=j;
                minPos=temp;
            }
        }
    }
    if(index!=-1){
        keys[index].value(line,&out,op);
    }
    return out;
}

