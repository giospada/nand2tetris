#include "InputReader.h"
#include <assert.h>

#define INPBUFFSIZE 1024

void readInput(Input *write,FILE* file)
{
    size_t inputSize=INPBUFFSIZE;
    char* buffer=calloc(inputSize,sizeof(char));
    while (fgets(buffer,inputSize, file)!=NULL)
    {
        char* temp=calloc((strlen(buffer)+10),sizeof(char));
        assert(temp!=NULL);
        temp=strcpy(temp,buffer);
        addElement(&write->input,temp);
    }
    fclose(file);
}

Input readFileFromARG(int argc, char const *argv[])
{
    Input input;
    input.error = 0;
    input.input = createAllocator();
    input.fileName=argv[1];
    FILE *inputFile;
    if (argc == 1)
    {
        inputFile = stdin;
    }
    else
    {
        inputFile = fopen(argv[1], "r");
    }
    if (inputFile == NULL)
    {
        input.error = 1;
    }
    else
    {
        readInput(&input, inputFile);
    }
    return input;
}
