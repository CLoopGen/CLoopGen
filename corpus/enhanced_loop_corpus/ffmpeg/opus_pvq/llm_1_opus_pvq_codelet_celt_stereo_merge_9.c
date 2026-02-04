#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern float mid;
extern int N;
extern int i;
extern float gain[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 2; j++) {
    for (i = 0; i < N; i++) {
        float value[2];
        value[0] = mid * X[i];
        value[1] = Y[i];
        X[i] = gain[j] * (value[0] - value[1]);
        Y[i] = gain[j] * (value[0] + value[1]);
    }
}
}
