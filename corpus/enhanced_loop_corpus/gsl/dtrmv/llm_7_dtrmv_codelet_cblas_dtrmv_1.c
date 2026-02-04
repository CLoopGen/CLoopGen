#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *restrict local_X = X;
const double *restrict local_A = A;
int local_ix = ix;
for (i = N; i > 0 && i--;) {
    double temp = 0.0;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += local_X[jx] * local_A[lda * i + j];
        jx += incX;
    }
    if (nonunit) {
        local_X[local_ix] = temp + local_X[local_ix] * local_A[lda * i + i];
    } else {
        local_X[local_ix] += temp;
    }
    local_ix -= incX;
}
ix = local_ix;
}
