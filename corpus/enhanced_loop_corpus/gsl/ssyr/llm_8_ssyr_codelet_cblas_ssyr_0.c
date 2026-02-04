#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const float tmp1 = alpha * X[ix];
    const float tmp2 = (incX != 0 && ix + incX < N * abs(incX)) ? alpha * X[ix + incX] : 0.0f;
    int jx1 = ix;
    int jx2 = ix + incX;
    for (j = i; j < N; j++) {
        A[lda * i + j] += X[jx1] * tmp1;
        if (i + 1 < N && j >= i + 1) {
            A[lda * (i + 1) + j] += X[jx2] * tmp2;
        }
        jx1 += incX;
        jx2 += incX;
    }
    ix += 2 * incX;
}
}
