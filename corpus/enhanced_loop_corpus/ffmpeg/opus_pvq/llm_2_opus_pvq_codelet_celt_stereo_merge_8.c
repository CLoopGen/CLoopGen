#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;
extern float xp;
extern float side;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            xp += X[i] * Y[i] + X[i+1] * Y[i+1];
            side += Y[i] * Y[i] + Y[i+1] * Y[i+1];
        } else {
            xp += X[i] * Y[i];
            side += Y[i] * Y[i];
        }
    }
}
