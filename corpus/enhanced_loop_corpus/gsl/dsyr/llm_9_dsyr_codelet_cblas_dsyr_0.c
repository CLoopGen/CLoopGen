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
for (i = 0; i < N; i += 2) {
    const double tmp1 = alpha * X[ix];
    int jx1 = ix;
    int i1 = i + 1;
    int update_ix = 0;
    for (j = i; j < N; j++) {
        A[lda * i + j] += X[jx1] * tmp1;
        if (i1 < N && j >= i1) {
            const double tmp2 = alpha * X[ix + incX];
            A[lda * i1 + j] += X[jx1] * tmp2;
        }
        jx1 += incX;
    }
    if (i1 < N) update_ix = 2 * incX;
    else update_ix = incX;
    ix += update_ix;
}
}
