#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration order
    int stride = incY * (N - 1);
    int step = -incY;
    int iy_temp = iy + stride;
    for (i = 0; i < N; i++) {
        Y[iy_temp] = 0.0f;
        iy_temp += step;
    }
    iy = iy_temp; // update global iy to reflect final index
}
