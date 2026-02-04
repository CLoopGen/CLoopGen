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
for (i = 0; i < lenY; i++) {
    double temp = 0.;
    const int j_min = (i <= L ? 0 : i - L);
    const int j_max = (i + U + 1 <= lenX ? i + U + 1 : lenX);
    if (j_min >= j_max) {
        iy += incY;
        continue;
    }
    int jx = (incX > 0 ? j_min * incX : ((lenX - 1) * (-incX)) + j_min * incX);
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    Y[iy] = (incY != 0) ? Y[iy] + alpha * temp : Y[iy];
    iy += incY;
}
}
