#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_X = (float*)malloc(N * sizeof(float));
if (!local_X) return;
for (int k = 0; k < N; k++) {
    local_X[k] = X[k * incX];
}
for (i = N - 1; i > 0 && i--;) {
    float tmp = local_X[i];
    for (j = i + 1; j < N; j++) {
        const float Aij = A[lda * i + j];
        tmp -= Aij * local_X[j];
    }
    if (nonunit) {
        local_X[i] = tmp / A[lda * i + i];
    } else {
        local_X[i] = tmp;
    }
}
for (int k = 0; k < N; k++) {
    X[k * incX] = local_X[k];
}
free(local_X);
}
