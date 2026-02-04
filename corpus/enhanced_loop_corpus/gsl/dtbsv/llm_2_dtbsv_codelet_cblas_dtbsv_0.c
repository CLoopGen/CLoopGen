#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N - 1; i >= 0; i--) {
    const int row_start = lda * i;
    double tmp = X[i * incX];
    const int j_min = i + 1;
    const int j_max = (N < i + K + 1) ? N : (i + K + 1);
    for (j = j_min; j < j_max; j++) {
        const int A_index = row_start + (j - i);
        const int X_index = j * incX;
        tmp -= A[A_index] * X[X_index];
    }
    const int diag_index = row_start;
    const int X_ix = i * incX;
    if (nonunit) {
        X[X_ix] = tmp / A[diag_index];
    } else {
        X[X_ix] = tmp;
    }
}
}
