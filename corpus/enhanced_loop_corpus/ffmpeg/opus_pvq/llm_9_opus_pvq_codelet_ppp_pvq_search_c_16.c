#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float sum1 = 0.0f, sum2 = 0.0f;
    for (i = 0; i < N; i++) {
        float val = X[i];
        float abs_val = (val >= 0) ? val : -val;
        sum1 += abs_val * 1.5f;
        sum2 += abs_val * 0.5f;
    }
    res += (sum1 + sum2);
}
