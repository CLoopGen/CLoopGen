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
extern int L;
extern int U;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i += 2) {
    double temp0 = 0.;
    double temp1 = 0.;
    const int j_min0 = (i > L ? i - L : 0);
    const int j_max0 = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx0 = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min0 * incX;
    for (j = j_min0; j < j_max0; j++) {
        temp0 += X[jx0] * A[(L - i + j) + i * lda];
        jx0 += incX;
    }
    Y[iy] += alpha * temp0;
    iy += incY;

    if (i + 1 < lenY) {
        const int j_min1 = ((i + 1) > L ? (i + 1) - L : 0);
        const int j_max1 = ((lenX) < (i + 1 + U + 1) ? (lenX) : (i + 1 + U + 1));
        int jx1 = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min1 * incX;
        for (j = j_min1; j < j_max1; j++) {
            temp1 += X[jx1] * A[(L - (i + 1) + j) + (i + 1) * lda];
            jx1 += incX;
        }
        Y[iy] += alpha * temp1;
        iy += incY;
    }
}
}
