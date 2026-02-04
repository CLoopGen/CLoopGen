#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i += 2) {
    float temp0 = 0., temp1 = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        temp0 += X[ix] * A[lda * i + j];
        if (i + 1 < lenY) {
            temp1 += X[ix] * A[lda * (i + 1) + j];
        }
        ix += incX;
    }
    Y[iy] += alpha * temp0;
    if (i + 1 < lenY) {
        Y[iy + incY] += alpha * temp1;
    }
    iy += 2 * incY;
}
}
