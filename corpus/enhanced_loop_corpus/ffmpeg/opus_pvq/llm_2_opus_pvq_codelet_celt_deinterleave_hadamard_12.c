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
    // Variant 1: Change memory access pattern to consecutive in inner loop by swapping loop order
    // This improves spatial locality for X and tmp when stride is large
    for (j = 0; j < N0; j++)
        for (i = 0; i < stride; i++)
            tmp[order[i] * N0 + j] = X[j * stride + i];
}
