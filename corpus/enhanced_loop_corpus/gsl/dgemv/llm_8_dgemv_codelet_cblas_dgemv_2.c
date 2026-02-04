#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    double temp1 = 0., temp2 = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    int j = 0;
    for (; j < lenX - 1; j += 2) {
        temp1 += X[ix] * A[lda * i + j];
        temp2 += X[ix + incX] * A[lda * i + j + 1];
        ix += 2 * incX;
    }
    for (; j < lenX; j++) {
        temp1 += X[ix] * A[lda * i + j];
        ix += incX;
    }
    Y[iy] += alpha * (temp1 + temp2);
    iy += incY;
}
}
