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
for (i = N - 2; i >= 0; i -= 3) {
    for (int offset = 0; offset < 3 && (i - offset) >= 0; ++offset) {
        int idx = i - offset;
        double temp = 0.;
        const int j_min = (K > idx ? 0 : idx - K);
        const int j_max = idx;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            temp += X[jx] * A[lda * j + (idx - j)];
            jx += incX;
        }
        if (nonunit) {
            X[ix - offset * incX] = temp + X[ix - offset * incX] * A[lda * idx + 0];
        } else {
            X[ix - offset * incX] += temp;
        }
    }
    ix -= 3 * incX;
}
}
