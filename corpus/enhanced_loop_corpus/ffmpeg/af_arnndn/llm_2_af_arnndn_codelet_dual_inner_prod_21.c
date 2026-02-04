#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y01;
extern  float *y02;
extern int N;
extern float xy01;
extern float xy02;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < N; i += 2) {
        xy01 += (x[i] * y01[i]);
        xy02 += (x[i] * y02[i]);
        if (i + 1 < N) {
            xy01 += (x[i + 1] * y01[i + 1]);
            xy02 += (x[i + 1] * y02[i + 1]);
        }
    }
}
