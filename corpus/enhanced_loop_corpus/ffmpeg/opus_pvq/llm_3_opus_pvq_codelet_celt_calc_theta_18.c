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
    // Variant 2: Reverse Consecutive Memory Access (traverse arrays from end to start)
    for (i = N - 1; i >= 0; i--) {
        e[0] += (X[i] + Y[i]) * (X[i] + Y[i]);
        e[1] += (X[i] - Y[i]) * (X[i] - Y[i]);
    }
}
