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
    float prev_val = 0.0f;
    for (i = 0; i < N; i++) {
        float current = Y[iy];
        Y[iy] = current * beta + prev_val;
        prev_val = current;
        iy += incY;
    }
}
