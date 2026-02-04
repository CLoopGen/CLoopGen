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
    int limit = N - (N % 4);
    for (i = 0; i < limit; i += 4) {
        sum1 += X[i] * X[i] + X[i+1] * X[i+1];
        sum2 += X[i+2] * X[i+2] + X[i+3] * X[i+3];
    }
    for (; i < N; i++) {
        sum1 += X[i] * X[i];
    }
    g += sum1 + sum2;
}
