#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *X;
extern  float *Y;
extern int N;
extern int i;
extern float e[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        if (i + 0 < N) {
            e[0] += X[i] * X[i];
            e[1] += Y[i] * Y[i];
        }
        if (i + 1 < N) {
            e[0] += X[i + 1] * X[i + 1];
            e[1] += Y[i + 1] * Y[i + 1];
        }
    }
}
