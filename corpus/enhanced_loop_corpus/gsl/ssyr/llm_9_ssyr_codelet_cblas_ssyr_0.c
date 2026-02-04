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
if (N <= 0) return;
const float tmp = alpha * X[ix];
int jx = ix;
for (j = 0; j < N; j++) {
    A[lda * 0 + j] += X[jx] * tmp;
    jx += incX;
}
ix += incX;
for (i = 1; i < N; i++) {
    const float tmp = alpha * X[ix];
    jx = ix;
    for (j = i; j < N; j += 2) {
        A[lda * i + j] += X[jx] * tmp;
        if (j + 1 < N) {
            A[lda * i + (j + 1)] += X[jx + incX] * tmp;
        }
        jx += 2 * incX;
    }
    ix += incX;
}
}
