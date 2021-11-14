#ifndef Allocator_File
#define Allocator_File

/*

È una struttura più delle funzioni che creano una specie di array dinamico,
fin ora non ha tutte le operazioni di un array, e in più ne ha alcune specifice per
il tipo di dato stirnga

*/

#include <stdlib.h>
#include <string.h>

#define ALLO_INIT_SIZE 8
typedef struct 
{
    int len;
    int allocatesize;
    void** items;
}Allocator;


Allocator createAllocator();
void* getFromAllocator(Allocator* all,int index);
void addElement(Allocator* all,void* el);
void freeAllocator();
void freeAllocatorAndElements();


#endif


