#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *restrict iy;
extern float *restrict X;
extern int N;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 0; i < N; i += 2)
        X[i] = g * iy[i];
}
