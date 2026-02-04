#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float temp = alpha * X[ix];
        Y[iy] = (i % 2 == 0) ? Y[iy] + temp : Y[iy];
        ix += incX;
        iy += incY;
    }
}
