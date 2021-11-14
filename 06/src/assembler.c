#include "InputReader.h"
#include "Labels.h"
#include "OutProcessor.h"
#include "SymbolicTable.h"



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
		Label lab = readAllLabels(&file);

		SymbolicTable st=genereateST();
		addLabelToST(&st,&lab);
#ifdef DBG
		puts("\nSybol table:\n");
		for (int i = 0; i < st.rows.len; i++){
			STRow* row=(STRow*) getFromAllocator(&st.rows,i);
			printf("%3d:%s:%d \n",i ,row->key,row->val);
		}
#endif

		writeAllToFile(&file,&st);
		freeAllocatorAndElements(&lab.el);
	}
	freeAllocatorAndElements(&file.input);
	return 0;
}
