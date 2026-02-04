#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern  float c;
extern  float s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (assume incX = incY = 1)
    // Arrays X and Y are accessed consecutively to improve cache locality
    for (i = 0; i < N; i++) {
        const float x = X[i];
        const float y = Y[i];
        X[i] = c * x + s * y;
        Y[i] = -s * x + c * y;
    }
}
