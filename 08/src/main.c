#include <stdio.h>
#include "InputReader.h"
#include "InstructionProcessor.h"
#include "OutProcessor.h"
#include "OperationSetting.h"

//run 
//for i in $(ls ../test/*.vm);do ./assembler $(echo $i| sed -r 's|^(.*?)\.\w+$|\1|').vm;../../../../tools/CPUEmulator.sh $(echo $i| sed -r 's|^(.*?)\.\w+$|\1|').tst ;done 

#define DBG

int main(int argc, char const *argv[])
{

	Input file = readFileFromARG(argc, argv);
	if (file.error == 0)
	{
		FILE* f=openFile(&file);
		OperationSetting op=createOperationSetting(&file);
		Allocator initAll=initOperation();
		writeAllocator(f,&initAll);
		freeAllocatorAndElements(&initAll);
		for (int i = 0; i < file.input.len; i++){
			char* line=(char *)getFromAllocator(&file.input, i);
			Allocator all=processLine(line,&op);
			writeAllocator(f,&all);
			freeAllocatorAndElements(&all);
		}
		freeOperationSetting(&op);
		fclose(f);
		
	}
	freeAllocatorAndElements(&file.input);
	return 0;
}
