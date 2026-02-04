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
for (j = 0; j < lenX; j++) {
    const float temp = alpha * X[ix];
    if (temp != 0.) {
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        i = 0;
        while (i < lenY - 3) {
            Y[iy] += temp * A[lda * j + i];
            Y[iy + incY] += temp * A[lda * j + i + 1];
            Y[iy + 2*incY] += temp * A[lda * j + i + 2];
            Y[iy + 3*incY] += temp * A[lda * j + i + 3];
            iy += 4 * incY;
            i += 4;
        }
        for (; i < lenY; i++) {
            Y[iy] += temp * A[lda * j + i];
            iy += incY;
        }
    }
    ix += incX;
}
}
