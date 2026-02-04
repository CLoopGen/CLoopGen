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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j += 2) {
    const float temp1 = alpha * X[ix];
    const float temp2 = (incX == 1 && j + 1 < lenX) ? alpha * X[ix + incX] : 0.0f;
    if (temp1 != 0.) {
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        for (i = 0; i < lenY; i++) {
            Y[iy] += temp1 * A[lda * j + i];
            iy += incY;
        }
    }
    if (j + 1 < lenX && temp2 != 0.) {
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        for (i = 0; i < lenY; i++) {
            Y[iy] += temp2 * A[lda * (j + 1) + i];
            iy += incY;
        }
    }
    ix += 2 * incX;
}
}
