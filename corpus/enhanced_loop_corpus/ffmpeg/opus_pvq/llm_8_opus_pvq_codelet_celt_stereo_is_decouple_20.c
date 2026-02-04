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
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            X[i]   = e_l * X[i] + e_r * Y[i];
            X[i+1] = e_l * X[i+1] + e_r * Y[i+1];
        } else {
            X[i] = e_l * X[i] + e_r * Y[i];
        }
    }
}
