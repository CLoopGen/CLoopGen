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
    int i;
    float el_sq = e_l * e_l;
    float er_sq = e_r * e_r;
    for (i = 0; i < N; i++) {
        X[i] = el_sq * X[i] * X[i] + er_sq * Y[i] * Y[i] + e_l * e_r * X[i];
    }
}
