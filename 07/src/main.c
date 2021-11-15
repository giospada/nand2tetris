#include "InputReader.h"



int main(int argc, char const *argv[])
{

	Input file = readFileFromARG(argc, argv);
	if (file.error == 0)
	{
#ifdef DBG
		puts("inputFile:\n");
		for (int i = 0; i < file.input.len; i++)
			printf("%s", (char *)getFromAllocator(&file.input, i));
#endif
    }
	return 0;
}
