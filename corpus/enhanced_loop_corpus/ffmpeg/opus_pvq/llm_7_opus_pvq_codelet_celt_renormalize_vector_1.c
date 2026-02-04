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
    int half = N / 2;
    for (i = 0; i < half; i++) {
        sum1 += X[i] * X[i];
        sum2 += X[N - i - 1] * X[N - i - 1];
    }
    if (N % 2 == 1)
        sum1 += X[half] * X[half];
    g += sum1 + sum2;
}
