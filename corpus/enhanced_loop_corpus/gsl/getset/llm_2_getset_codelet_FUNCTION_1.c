#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern size_t M;
    extern size_t i;
    unsigned int *array = (unsigned int*)malloc(M * sizeof(unsigned int));
    if (!array) return;
    for (i = 0; i < M; i++) {
        unsigned int k = array[i]; // Consecutive forward access
        k = k + 1;
    }
    free(array);
}
