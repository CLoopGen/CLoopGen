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
    float temp_e0 = 0.0f;
    float temp_e1 = 0.0f;
    for (i = 0; i < N; i++) {
        temp_e0 += X[i] * X[i];
        temp_e1 += Y[i] * Y[i];
    }
    e[0] += temp_e0;
    e[1] += temp_e1;
}
