#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float beta_sq = beta * beta;
    for (i = 0; i < N; i++) {
        Y[iy] *= beta_sq;
        Y[iy] += beta; // Additional arithmetic to increase computational intensity
        iy += incY;
    }
}
