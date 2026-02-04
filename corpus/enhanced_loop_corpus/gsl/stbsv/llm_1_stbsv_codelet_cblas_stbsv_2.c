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
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
float *X_start = X;
int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
for (i = 0; i < N; i++) {
    float tmp = X[base_ix + i * incX];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const float Aji = A[(i - j) + lda * j];
        tmp -= Aji * X[base_ix + j * incX];
    }
    if (nonunit) {
        tmp /= A[0 + lda * i];
    }
    X[base_ix + i * incX] = tmp;
}
}
