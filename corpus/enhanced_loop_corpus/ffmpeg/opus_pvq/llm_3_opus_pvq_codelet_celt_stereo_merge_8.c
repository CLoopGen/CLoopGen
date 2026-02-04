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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = N - 1; i >= 0; i--) {
        xp += X[i] * Y[i];
        side += Y[i] * Y[i];
    }
}
