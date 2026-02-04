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
if (lenY > 0) {
    double temp = 0.;
    const int j_min = (0 > L ? 0 - L : 0);
    const int j_max = ((lenX) < (0 + U + 1) ? (lenX) : (0 + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - 0 + j) + 0 * lda];
        jx += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
for (i = 1; i < lenY; i++) {
    double temp = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
