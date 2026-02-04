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
    double temp = 0.0;
    int ix_start = (incX > 0) ? 0 : (lenX - 1) * (-incX);
    int j = 0;
    for (; j < lenX; j++) {
        int ix = ix_start + j * incX;
        if (ix >= 0) {
            temp += X[ix] * A[lda * i + j];
        }
    }
    if (iy >= 0) {
        Y[iy] += alpha * temp;
    }
    iy += incY;
}
}
