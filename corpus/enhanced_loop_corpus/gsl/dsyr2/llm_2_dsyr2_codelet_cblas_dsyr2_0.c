#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[i * incX];
    const double tmp2 = alpha * Y[i * incY];
    for (j = i; j < N; j++) {
        A[j + i * lda] += tmp1 * Y[j * incY] + tmp2 * X[j * incX];
    }
}
}
