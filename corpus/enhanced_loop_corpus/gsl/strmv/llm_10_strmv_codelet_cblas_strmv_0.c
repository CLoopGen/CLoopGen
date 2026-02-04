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
for (i = 0; i < N; i += 2) {
    float temp1 = 0.;
    float temp2 = 0.;
    const int j_min1 = i + 1;
    const int j_max1 = N;
    const int j_min2 = (i+1) + 1;
    const int j_max2 = N;
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min1 * incX;
    int jx2 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min2 * incX;
    
    if (i+1 >= N) break;

    for (j = j_min1; j < j_max1; j++) {
        temp1 += X[jx1] * A[lda * i + j];
        jx1 += incX;
    }
    for (j = j_min2; j < j_max2; j++) {
        temp2 += X[jx2] * A[lda * (i+1) + j];
        jx2 += incX;
    }

    if (nonunit) {
        X[ix] = temp1 + X[ix] * A[lda * i + i];
        X[ix + incX] = temp2 + X[ix + incX] * A[lda * (i+1) + (i+1)];
    } else {
        X[ix] += temp1;
        X[ix + incX] += temp2;
    }
    ix += 2 * incX;
}
}
