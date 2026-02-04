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
    g = 0.0f;
    for (i = 0; i < N; i += 2) {
        float sum_sq = 0.0f;
        sum_sq += X[i] * X[i];
        if (i + 1 < N) {
            sum_sq += X[i + 1] * X[i + 1];
        }
        g += sum_sq;
    }
}
