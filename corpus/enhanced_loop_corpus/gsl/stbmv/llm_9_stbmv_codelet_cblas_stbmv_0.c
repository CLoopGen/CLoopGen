#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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
for (i = 0; i < N; i++) {
    float temp = (nonunit ? A[lda * i + 0] : 1.) * X[ix];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j += 2) {
        if (j + 1 < j_max) {
            temp += X[jx] * A[lda * i + (j - i)] +
                    X[jx + incX] * A[lda * i + (j + 1 - i)];
            jx += 2 * incX;
        } else {
            temp += X[jx] * A[lda * i + (j - i)];
            jx += incX;
        }
    }
    X[ix] = temp;
    ix += incX;
}
}
