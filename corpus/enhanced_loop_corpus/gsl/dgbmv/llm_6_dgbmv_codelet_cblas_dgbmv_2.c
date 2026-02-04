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
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    int offset_base = i * lda - i;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L + j) + offset_base];
        jx += incX;
    }
    Y[iy] = alpha * temp + Y[iy]; // Reordered operation to emphasize RAW on Y[iy]
    iy += incY;
}
}
