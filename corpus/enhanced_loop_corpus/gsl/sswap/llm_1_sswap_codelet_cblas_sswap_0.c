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
    if (N > 0) {
        for (i = 0; i < N; i += 2) {
            // First iteration of unrolled pair
            if (i < N) {
                const float tmp1 = X[ix];
                X[ix] = Y[iy];
                Y[iy] = tmp1;
                ix += incX;
                iy += incY;
            }
            // Second iteration of unrolled pair
            if (i + 1 < N) {
                const float tmp2 = X[ix];
                X[ix] = Y[iy];
                Y[iy] = tmp2;
                ix += incX;
                iy += incY;
            }
        }
    }
}
