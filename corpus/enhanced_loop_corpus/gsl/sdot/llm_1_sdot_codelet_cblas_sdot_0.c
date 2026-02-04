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
    int outer;
    for (outer = 0; outer < N; outer++) {
        int i = outer;
        r += X[ix] * Y[iy];
        ix += incX;
        iy += incY;
    }
}
