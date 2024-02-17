#include <stdio.h>
#include <stdbool.h>

#define HEAP_SIZE 1048576 //1MB Heap size
#define Max_HEAP_CHUNK 100 //MAx number of memory chuncks the heap can be devided in to

typedef struct{
  void* start; //address
  size_t size; //size
  __int8_t state; //state
  void* next;
  void* prev;
}HeapChunk;//An object defining a chunk of heap



char heap[HEAP_SIZE]; //Heap
HeapChunk entry_chunk = {heap, 1048576, 0, NULL, NULL};


bool firstRun = true; //determine firstRun of allocator function


void* hmalloc(size_t size){

  if (size <= 0) //Return null if 0bytes of memory is asked
    return NULL;
  
  HeapChunk* chunk; //Pointer to be returned
  HeapChunk next;

   
  chunk = &entry_chunk;

  while (size > chunk->size || chunk->state == 1)
    chunk = (HeapChunk*) chunk->next;
  

  chunk->state = 1;
  if (chunk->size != size){
    next.prev = &chunk; 
    chunk->next = &next;
    
    next.size = chunk->size - size;
    next.start = chunk->start + size;

    chunk->size = size;
  }
  

  return chunk->start;
}


void hmfree(void* ptr){
    return;
}
  
