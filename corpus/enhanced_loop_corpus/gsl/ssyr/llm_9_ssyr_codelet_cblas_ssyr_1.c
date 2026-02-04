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
for (i = 1; i < N; i += 2) {
    const float tmp1 = alpha * X[ix];
    const float tmp2 = alpha * X[ix + incX];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j++) {
        A[lda * i + j] += X[jx] * tmp1;
        if (i + 1 < N) {
            A[lda * (i + 1) + j] += X[jx] * tmp2;
        }
        jx += incX;
    }
    ix += 2 * incX;
}
}
