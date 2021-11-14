#ifndef Labels_File
#define Labels_File

/*

Labels è una struttura composta da le Label codelines che sono le line di codice
contenute in inp, due allocator key e val che contengono rispettivamente i valori
dell'etichette e la riga in cui si trovano

*/

#include "Allocator.h"


typedef struct 
{
    char* key;
    int val;
}LRow;

typedef struct 
{
    int codeLines;
    Allocator el;
}Label;

#include <string.h>
#include "LineProcessor.h"
#include "InputReader.h"



Label readAllLabels(Input* inp);

#endif



