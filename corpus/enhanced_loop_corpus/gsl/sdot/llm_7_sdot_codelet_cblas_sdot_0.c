#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_r = 0.0f;
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        local_r += X[local_ix] * Y[local_iy];
        local_ix += incX;
        local_iy += incY;
    }
    r += local_r;
}
