#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming an array context, simulate strided access by incrementing index with stride > 1
    int *array = (int*)malloc(w2 * sizeof(int));
    if (!array) return;
    for (x = 0; x < w2; x += 2) {  // Stride of 2: access every second element
        array[x] = x * 2;
    }
    free(array);
}
