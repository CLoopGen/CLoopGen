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
for (i = 0; i < lenY; i++) {
    float temp1 = 0., temp2 = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX - 1; j += 2) {
        temp1 += X[ix] * A[lda * i + j];
        if (j + 1 < lenX) {
            temp2 += X[ix + incX] * A[lda * i + j + 1];
        }
        ix += 2 * incX;
    }
    temp1 += temp2;
    if (lenX % 2 == 1) {
        temp1 += X[ix - incX] * A[lda * i + lenX - 1];
    }
    Y[iy] += alpha * temp1;
    iy += incY;
}
}
