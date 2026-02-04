#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    int jx = ix;
    for (j = i; j < N; j += 2) {
        A[lda * i + j] += X[jx] * tmp;
        if (j + 1 < N) {
            A[lda * i + (j + 1)] += X[jx + incX] * tmp;
        }
        jx += 2 * incX;
    }
    ix += incX;
}
}
