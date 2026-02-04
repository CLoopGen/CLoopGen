#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (i = 0; i < N; i++) {
        temp = X[ix] + temp; // Introduces loop-carried RAW dependency via 'temp'
        Y[iy] = temp;
        ix += incX;
        iy += incY;
    }
}
