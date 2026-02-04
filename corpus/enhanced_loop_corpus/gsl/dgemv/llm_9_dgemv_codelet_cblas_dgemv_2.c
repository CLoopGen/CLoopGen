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
int stride = (lenX > 4) ? 4 : 1;
for (i = 0; i < lenY; i++) {
    double temp = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    int j = 0;
    for (; j <= lenX - stride; j += stride) {
        temp += X[ix] * A[lda * i + j];
        if (stride >= 2) temp += X[ix + incX] * A[lda * i + j + 1];
        if (stride >= 3) temp += X[ix + 2*incX] * A[lda * i + j + 2];
        if (stride >= 4) temp += X[ix + 3*incX] * A[lda * i + j + 3];
        ix += stride * incX;
    }
    for (; j < lenX; j++) {
        temp += X[ix] * A[lda * i + j];
        ix += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
