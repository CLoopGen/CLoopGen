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
    // Variant 2: Reverse consecutive memory access
    for (i = N - 1; i >= 0; i--)
        X[i] = g * iy[i];
}
