#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float sum = X[i] + X[i] * 0.5f;
        float scaled = sum * 1.2f;
        Y[i] = scaled - 0.2f * X[i];
    }
}
