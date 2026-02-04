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
    for (i = 0; i < N; i++) {
        if (i % 2 == 0) {
            const float tmp = X[ix];
            X[ix] = Y[iy];
            Y[iy] = tmp;
        }
        ix += incX;
        iy += incY;
    }
}
