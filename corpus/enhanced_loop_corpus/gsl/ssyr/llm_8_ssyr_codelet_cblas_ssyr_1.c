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
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i + 1; j += 2) {
        A[lda * i + j] += X[jx] * tmp;
        if (j + 1 <= i) {
            A[lda * i + (j + 1)] += X[jx + incX] * tmp;
        }
        jx += 2 * incX;
    }
    ix += incX;
}
}
