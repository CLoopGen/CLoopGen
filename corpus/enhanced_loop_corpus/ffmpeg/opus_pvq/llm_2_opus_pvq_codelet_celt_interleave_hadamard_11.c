#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *tmp;
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;
extern  uint8_t *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use consecutive writes by transposing the iteration order
    // This improves spatial locality in writing to tmp by making writes consecutive
    for (j = 0; j < N0; j++)
        for (i = 0; i < stride; i++)
            tmp[j * stride + i] = X[order[i] * N0 + j];
}
