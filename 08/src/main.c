#include <stdio.h>
#include "InputReader.h"
#include "InstructionProcessor.h"
#include "OutProcessor.h"
#include "OperationSetting.h"

//run
//for i in $(ls ../test/*.vm);do ./assembler $(echo $i| sed -r 's|^(.*?)\.\w+$|\1|').vm;../../../../tools/CPUEmulator.sh $(echo $i| sed -r 's|^(.*?)\.\w+$|\1|').tst ;done


int main(int argc, char const *argv[])
{

	InputDir dirInput = readDirFromArgs(argc, argv);
	if (dirInput.error == 0)
	{
		FILE *f = openDir(&dirInput);
		OperationSetting op = createOperationSettingWithoutFile();
		Allocator initAll = initOperation(&op);
		writeAllocator(f, &initAll);
		freeAllocatorAndElements(&initAll);
		for (int i = 0; i < dirInput.files.len; i++)
		{
			char* fileName = (char*)getFromAllocator(&dirInput.files, i);
			Input file=readFileFrom(argv[1],fileName);
			printf("doing:%s\n", file.fileName);
 			updateNameOfOperationSetting(&op,&file);

			if (file.error == 0)
			{
				for (int i = 0; i < file.input.len; i++)
				{
					char *line = (char *)getFromAllocator(&file.input, i);
					Allocator all = processLine(line, &op);
#ifdef DBG
					addElement(&all, strConcat("//", line));
#endif
					writeAllocator(f, &all);
					freeAllocatorAndElements(&all);
				}
			}
			freeAllocatorAndElements(&file.input);
			free(file.fileName);
		}
		freeAllocatorAndElements(&dirInput.files);
		freeOperationSetting(&op);
		fclose(f);
	}
	return 0;
}
