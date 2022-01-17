#include "InputReader.h"


InputDir readDirFromArgs(int argc, char const *argv[])
{
    InputDir dir;
    dir.error = 0;
    dir.files = createAllocator();
    if (argc <= 1)
    {
        dir.error = 1;
    }
    else
    {
        dir.dirName = argv[1];
        struct dirent *fileInp;
        DIR *dirObj;
        dirObj = opendir(dir.dirName);
        if (dirObj)
        {
            while ((fileInp = readdir(dirObj)) != NULL)
            {
                if (finishWith(fileInp->d_name, ".vm"))
                {
                    addElement(&dir.files, copyString(fileInp->d_name));
                }
            }
            free(fileInp);
        }
        closedir(dirObj);
    }
    return dir;
}

Input readFileFrom(char* dir,char* name)
{
    
    Input input;
    input.error = 0;
    input.input = createAllocator();
    input.fileName=copyString(name);
    FILE *inputFile;
    char *concat;
    if(finishWith(dir,"/")){
        concat=strConcat(dir,name);
    }else{
        char* temp=strConcat(dir,"/");
        concat=strConcat(temp,name);
        free(temp);
    }
    inputFile = fopen(concat, "r");
    if (inputFile == NULL)
    {
        input.error = 1;
    }
    else
    {
        readInput(&input, inputFile);
    }
    free(concat);
    return input;
}


void readInput(Input *write, FILE *file)
{
    size_t inputSize = INPBUFFSIZE;
    char *buffer = calloc(inputSize, sizeof(char));
    while (fgets(buffer, inputSize, file) != NULL)
    {
        char *temp = calloc((strlen(buffer) + 10), sizeof(char));
        assert(temp != NULL);
        temp = strcpy(temp, buffer);
        addElement(&write->input, temp);
    }
    free(buffer);
    fclose(file);
}