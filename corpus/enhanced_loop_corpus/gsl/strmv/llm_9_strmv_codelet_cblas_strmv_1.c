#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N / 2; i > 0 && i--;) {
    float temp_upper = 0.;
    float temp_lower = 0.;
    const int j_min = 0;
    const int j_max_upper = i;
    const int j_max_lower = N - i - 1;
    int jx_upper = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jx_lower = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;

    for (j = j_min; j < j_max_upper; j++) {
        temp_upper += X[jx_upper] * A[lda * i + j];
        temp_lower += X[jx_lower] * A[lda * (N - i - 1) + j];
        jx_upper += incX;
        jx_lower += incX;
    }

    if (nonunit) {
        X[ix] = temp_upper + X[ix] * A[lda * i + i];
        X[ix - (N/2) * incX] = temp_lower + X[ix - (N/2) * incX] * A[lda * (N - i - 1) + (N - i - 1)];
    } else {
        X[ix] += temp_upper;
        X[ix - (N/2) * incX] += temp_lower;
    }
    ix -= incX;
}
}
