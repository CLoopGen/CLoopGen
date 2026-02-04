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
    for (i = 0; i < N; i++) {
        if (X[i] >= 0) {
            e[0] += X[i] * X[i];
        }
        if (Y[i] >= 0) {
            e[1] += Y[i] * Y[i];
        }
    }
}
