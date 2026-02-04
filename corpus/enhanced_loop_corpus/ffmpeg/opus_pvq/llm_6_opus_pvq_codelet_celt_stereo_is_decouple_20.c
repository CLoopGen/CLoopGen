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
    float el = e_l;
    float er = e_r;
    float *x = X;
    float *y = Y;
    int n = N;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            x[i]     = el * x[i]     + er * y[i];
            x[i + 1] = el * x[i + 1] + er * y[i + 1];
        } else {
            x[i] = el * x[i] + er * y[i];
        }
    }
}
