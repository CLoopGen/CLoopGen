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
    if (N > 0) {
        i = 0;
        for (; i < N; ) {
            Y[iy] = X[ix];
            ix += incX;
            iy += incY;
            i++;
            if (i < N) {
                Y[iy] = X[ix];
                ix += incX;
                iy += incY;
                i++;
            }
        }
    }
}
