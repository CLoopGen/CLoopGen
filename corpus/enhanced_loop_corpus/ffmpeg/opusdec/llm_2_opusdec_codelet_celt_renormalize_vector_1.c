#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 0; i < N; i += 2)
        g += X[i] * X[i];
}
