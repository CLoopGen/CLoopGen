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
float* X_base = X;
int* indices = (int*)malloc(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    indices[idx] = idx * incX;
}
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    for (j = 0; j < i; j++) {
        const float Aij = A[lda * i + j];
        tmp -= Aij * X_base[indices[j]];
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
free(indices);
}
