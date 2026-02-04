#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_x, temp_y;
    for (i = 0; i < N; i++) {
        temp_x = X[ix];
        temp_y = Y[iy];
        X[ix] = temp_y;
        Y[iy] = temp_x;
        ix += incX;
        iy += incY;
    }
}
