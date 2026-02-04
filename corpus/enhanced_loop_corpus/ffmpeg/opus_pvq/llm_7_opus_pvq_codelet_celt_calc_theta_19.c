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
        float xi = X[i];
        float yi = Y[i];
        e[0] = e[0] + xi * xi;
        e[1] = e[1] + yi * yi;
    }
}
