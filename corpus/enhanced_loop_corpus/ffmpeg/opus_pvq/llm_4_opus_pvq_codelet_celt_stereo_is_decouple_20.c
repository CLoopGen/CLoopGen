#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern float e_l;
extern float e_r;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    float el = e_l;
    float er = e_r;
    float *x = X;
    float *y = Y;
    for (i = 0; i < N; i++) {
        x[i] = el * x[i] + er * y[i];
    }
}
