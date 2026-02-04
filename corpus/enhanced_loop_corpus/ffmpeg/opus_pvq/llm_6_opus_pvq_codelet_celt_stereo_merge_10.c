#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_X = X;
    float *local_Y = Y;
    int local_N = N;
    for (i = 0; i < local_N; i++) {
        local_Y[i] = local_X[i];
    }
}
