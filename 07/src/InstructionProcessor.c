#include "InstructionProcessor.h"

#define NINST 18

typedef struct{
    char* key;
    void (*value)(char*,Allocator*);
}KeyVal;


void add(char* inp,Allocator* all){

}


KeyVal keys[]={
    {.key="add",.value=&add},
    {.key="sub",.value=&add},
    {.key="neg",.value=&add},
    {.key="eq",.value=&add},
    {.key="gt",.value=&add},
    {.key="lt",.value=&add},
    {.key="and",.value=&add},
    {.key="or",.value=&add},
    {.key="not",.value=&add},
    {.key="push",.value=&add},
    {.key="pop",.value=&add},
    {.key="label",.value=&add},
    {.key="goto",.value=&add},
    {.key="if-goto",.value=&add},
    {.key="function",.value=&add},
    {.key="call",.value=&add},
    {.key="return",.value=&add},
    {.key="//",.value=&add}
};

Allocator processLine(char *line)
{
    Allocator out = createAllocator();
    int lenLine=strlen(line);
    int processed=0;
    for (int i = 0; i < lenLine && !processed; i++)
    {
        int index=0;
        
        for (int j = 0; j < NINST && !processed; j++)
        {
            KeyVal current=keys[j];
            if(strcmp(line,current.key)){
                    
                processed=1;
            }
        }
    }
    return out;
}
