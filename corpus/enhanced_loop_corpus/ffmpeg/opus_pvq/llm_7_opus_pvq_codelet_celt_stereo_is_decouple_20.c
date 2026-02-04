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
    float temp;
    float el = e_l;
    float er = e_r;
    for (i = 0; i < N; i++) {
        temp = el * X[i] + er * Y[i];
        X[i] = temp;
    }
}
