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
    int i1;
    for (i1 = 0; i1 < N; i1 += 2) {
        sum1 += X[i1] * X[i1];
        if (i1 + 1 < N)
            sum2 += X[i1 + 1] * X[i1 + 1];
    }
    g += sum1 + sum2;
}
