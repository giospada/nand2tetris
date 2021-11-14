#include "Allocator.h"

Allocator createAllocator(){
    Allocator allocator;
    allocator.len=0;
    allocator.allocatesize=ALLO_INIT_SIZE;
    allocator.items=calloc(allocator.allocatesize,sizeof(void*));
    return allocator;
}
void* getFromAllocator(Allocator* all,int index){
    if(0<=index && index<=all->len)
        return all->items[index];
    return NULL;

}
void addElement(Allocator* all,void* el){
    if(all->len==all->allocatesize){
        all->allocatesize*=2;
        all->items=realloc(all->items, sizeof(void *) * all->allocatesize);
    }
    all->items[all->len]=el;
    all->len++;
}


void freeAllocator(Allocator* all){
    free(all->items);
}
void freeAllocatorAndElements(Allocator* all){
    for(int i=0;i<all->len;i++){
        free(all->items[i]);
    }
    freeAllocator(all);
}