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
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_accum[N]; // Introduce temporary array to remove WAW and WAR dependencies via privatization
for (i = 0; i < N; i++) {
    temp_accum[i] = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp_accum[i] += X[jx] * A[lda * j + (K - j + i)];
        jx += incX;
    }
}
// Second loop: update X without interference
int local_ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 0; i < N; i++) {
    if (nonunit) {
        X[local_ix] = temp_accum[i] + X[local_ix] * A[lda * i + K];
    } else {
        X[local_ix] += temp_accum[i];
    }
    local_ix += incX;
}
}
