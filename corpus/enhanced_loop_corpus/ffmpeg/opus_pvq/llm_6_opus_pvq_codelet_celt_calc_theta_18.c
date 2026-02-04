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
    float temp_e0 = e[0];
    float temp_e1 = e[1];
    for (i = 0; i < N; i++) {
        float sum = X[i] + Y[i];
        float diff = X[i] - Y[i];
        temp_e0 += sum * sum;
        temp_e1 += diff * diff;
    }
    e[0] = temp_e0;
    e[1] = temp_e1;
}
