#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
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
for (i = 1; i < N; i++) {
    double tmp = X[index_map[i]];
    for (j = 0; j < i; j++) {
        const double Aij = A[lda * i + j];
        tmp -= Aij * X[index_map[j]];
    }
    if (nonunit) {
        X[index_map[i]] = tmp / A[lda * i + i];
    } else {
        X[index_map[i]] = tmp;
    }
}
}
