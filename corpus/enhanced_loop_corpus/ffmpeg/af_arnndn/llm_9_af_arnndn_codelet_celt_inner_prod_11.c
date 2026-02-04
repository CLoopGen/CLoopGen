#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int N;
extern float xy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f, sum2 = 0.0f, sum3 = 0.0f, sum4 = 0.0f;
    int i = 0;
    for (; i < (N - 3); i += 4) {
        sum1 += x[i]   * y[i];
        sum2 += x[i+1] * y[i+1];
        sum3 += x[i+2] * y[i+2];
        sum4 += x[i+3] * y[i+3];
    }
    xy += sum1 + sum2 + sum3 + sum4;
    for (; i < N; i++) {
        xy += x[i] * y[i];
    }
}
