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
    for (i = 0; i < N; i += 2) {
        const float x1 = X[ix];
        const float y1 = Y[iy];
        X[ix] = c * x1 + s * y1;
        Y[iy] = -s * x1 + c * y1;
        ix += incX;
        iy += incY;

        if (i + 1 < N) {
            const float x2 = X[ix];
            const float y2 = Y[iy];
            X[ix] = c * x2 + s * y2;
            Y[iy] = -s * x2 + c * y2;
            ix += incX;
            iy += incY;
        }
    }
}
