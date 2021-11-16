#include <stdio.h>
#include "InputReader.h"
#include "InstructionProcessor.h"
#include "OutProcessor.h"


#define DBG

int main(int argc, char const *argv[])
{
	Input file = readFileFromARG(argc, argv);
	if (file.error == 0)
	{
		FILE* f=openFile(&file);
		Allocator initAll=initOperation();
		writeAllocator(f,&initAll);
		freeAllocatorAndElements(&initAll);
		for (int i = 0; i < file.input.len; i++){
			char* line=(char *)getFromAllocator(&file.input, i);
			Allocator all=processLine(line);
			writeAllocator(f,&all);
			freeAllocatorAndElements(&all);
		}
		fclose(f);
		
	}
	freeAllocatorAndElements(&file.input);
	return 0;
}
