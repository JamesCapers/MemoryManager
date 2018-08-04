//
//  main.c
//  MemoryHandler
//
//  Created by James Capers on 03/08/2018.
//  Copyright © 2018 James Capers. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Define some helpful debug output
#ifdef DEBUG
#define PRINT(fmt,...) {printf("%s ", __FILE__); printf("(%i) ", __LINE__); printf(fmt, ##__VA_ARGS__);}
#define ERROR(fmt,...) {printf("%s ", __FILE__); printf("(%i) ", __LINE__); printf("ERROR: "); printf(fmt, ##__VA_ARGS__); exit(EXIT_FAILURE);}
#else
#define PRINT(fmt,...) {printf(fmt, ##__VA_ARGS__);}
#define ERROR(fmt,...) {printf("ERROR: "); printf(fmt, ##__VA_ARGS__); exit(EXIT_FAILURE);}
#endif

// Size in terms of numner of elements NOT bytes!!
#define ALLOC_INT(size) AllocateMemory(size * sizeof(int))
// Free the memory
#define FREE(ptr) freeMemory((void**) &ptr)

// Memory utility functions prototypes
void freeMemory(void** ptr);
void* AllocateMemory(size_t n_bytes);

int main(int argc, const char * argv[]) {
    
    int N = 0;
    
    PRINT("Memory Handler\n");
    
    PRINT("Enter array length\n");
    scanf("%i", &N);
    
    if(N == 666){
        ERROR("NOPE\n");
    }
    
    int* array = ALLOC_INT(N);
    
    for(int i = 0; i < N; i++){
        array[i] = 2*i;
    }
    for(int i = 0; i < N; i++){
        printf("%i\t", array[i]);
    }
    printf("\n");
    
    FREE(array);
    
    if(array == NULL){
        ERROR("Memory is null\n");
    }
    
    return EXIT_SUCCESS;
}

void* AllocateMemory(size_t n_bytes)
{
    
    PRINT("Allocating %i bytes\n", (int)n_bytes);
    void* p = malloc(n_bytes);
    
    if(p == NULL){
        ERROR("Memory allocation failed\n");
    }
    
    return p;
}

void freeMemory(void** ptr)
{
    if(*ptr != NULL && ptr != NULL){
        free(*ptr);
        *ptr = NULL;
    }
    else{
        ERROR("Cannot free memory\n");
    }
}
