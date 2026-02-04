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
    float temp = beta;
    for (i = 0; i < N; i++) {
        float prev = Y[iy];
        Y[iy] *= temp;
        temp = prev * 0.5f; // Introduce RAW and loop-carried dependency: current iteration depends on prior Y[iy]
        iy += incY;
    }
}
