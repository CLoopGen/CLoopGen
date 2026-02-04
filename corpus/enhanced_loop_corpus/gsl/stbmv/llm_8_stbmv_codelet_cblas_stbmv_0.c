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
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        float temp1 = (nonunit ? A[lda * i + 0] : 1.) * X[ix];
        float temp2 = (nonunit ? A[lda * (i+1) + 0] : 1.) * X[ix + incX];
        const int j_min = i + 1;
        const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
        const int j_min2 = i + 2;
        const int j_max2 = ((N) < (i + K + 2) ? (N) : (i + K + 2));
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        int jx2 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min2 * incX;
        for (j = j_min; j < j_max; j++) {
            temp1 += X[jx] * A[lda * i + (j - i)];
            if (j >= i + 2) {
                temp2 += X[jx2] * A[lda * (i+1) + (j - (i+1))];
                jx2 += incX;
            }
            jx += incX;
        }
        X[ix] = temp1;
        X[ix + incX] = temp2;
        ix += 2 * incX;
    } else {
        float temp = (nonunit ? A[lda * i + 0] : 1.) * X[ix];
        const int j_min = i + 1;
        const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            temp += X[jx] * A[lda * i + (j - i)];
            jx += incX;
        }
        X[ix] = temp;
        ix += incX;
    }
}
}
