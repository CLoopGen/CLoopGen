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
    float sum1 = 0.0f, sum2 = 0.0f;
    int stride = 2;
    for (i = 0; i < N - 1; i += stride) {
        sum1 += X[i] * X[i];
        sum2 += X[i + 1] * X[i + 1];
    }
    if (i < N)
        sum1 += X[i] * X[i];
    g += sum1 + sum2;
}
