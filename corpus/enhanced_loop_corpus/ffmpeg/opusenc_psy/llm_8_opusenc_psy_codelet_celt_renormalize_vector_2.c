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
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Each iteration now performs two multiplications and one addition
    for (i = 0; i < N; i++) {
        X[i] = X[i] * g + X[i] * 0.5f;
    }
}
