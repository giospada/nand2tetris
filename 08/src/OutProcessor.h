#ifndef  OUTPROCESSOR_FILE
#define OUTPROCESSOR_FILE

#include "InputReader.h"
#include <stdio.h>
#include "Allocator.h"

// aggiunge l'estensione al file di output
char* fileName(Input* inp);
// apre il file se è settata la flag di debug lo mette nello stdout
FILE* openFile(Input* inp);
//scrive tutto quello che c'è nell'alocator (per ogni elemento aggiunge "\n")
void writeAllocator(FILE* f,Allocator* all);


#endif