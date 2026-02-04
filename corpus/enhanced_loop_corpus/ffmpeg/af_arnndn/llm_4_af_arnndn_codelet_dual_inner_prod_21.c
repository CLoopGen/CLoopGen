#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y01;
extern  float *y02;
extern int N;
extern float xy01;
extern float xy02;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    for (int i = 0; i < N; i++) {
        if (x[i] != 0.0f) {
            sum1 += x[i] * y01[i];
            sum2 += x[i] * y02[i];
        }
    }
    xy01 += sum1;
    xy02 += sum2;
}
