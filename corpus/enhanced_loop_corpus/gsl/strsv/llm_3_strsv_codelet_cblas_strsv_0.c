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
int *index_map = (int*)alloca(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = idx * incX;
}
for (i = N - 1; i > 0 && i--;) {
    float tmp = X[index_map[i]];
    for (j = i + 1; j < N; j++) {
        const float Aij = A[lda * i + j];
        tmp -= Aij * X[index_map[j]];
    }
    if (nonunit) {
        X[index_map[i]] = tmp / A[lda * i + i];
    } else {
        X[index_map[i]] = tmp;
    }
}
}
