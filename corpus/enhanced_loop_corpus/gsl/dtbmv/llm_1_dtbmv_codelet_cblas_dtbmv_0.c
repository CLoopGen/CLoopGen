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
if (N > 0) {
    const int total_iterations = N;
    int outer_unroll_factor = 2;
    for (i = 0; i < total_iterations; i += outer_unroll_factor) {
        int bound_i1 = i + 1;
        for (int u = 0; u < outer_unroll_factor && i + u < total_iterations; u++) {
            int ii = i + u;
            double temp = (nonunit ? A[lda * ii + 0] : 1.) * X[ix];
            const int j_min = ii + 1;
            const int j_max = ((N) < (ii + K + 1) ? (N) : (ii + K + 1));
            int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
            for (j = j_min; j < j_max; j++) {
                temp += X[jx] * A[lda * ii + (j - ii)];
                jx += incX;
            }
            X[ix] = temp;
            ix += incX;
        }
    }
}
}
