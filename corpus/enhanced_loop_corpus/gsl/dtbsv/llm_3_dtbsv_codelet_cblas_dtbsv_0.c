#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)alloca(N * sizeof(int));
for (int idx = 0; idx < N; idx++) {
    index_map[idx] = idx;
}
for (i = N - 1; i >= 0; i--) {
    int mapped_i = index_map[i];
    double tmp = X[mapped_i * incX];
    const int j_min = mapped_i + 1;
    const int j_max = (N < mapped_i + K + 1) ? N : (mapped_i + K + 1);
    for (j = j_min; j < j_max; j++) {
        int mapped_j = j;
        double Aij = A[lda * mapped_i + (mapped_j - mapped_i)];
        tmp -= Aij * X[mapped_j * incX];
    }
    if (nonunit) {
        X[mapped_i * incX] = tmp / A[lda * mapped_i];
    } else {
        X[mapped_i * incX] = tmp;
    }
}
}
