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
double *local_X = (double*)malloc(N * sizeof(double));
if (!local_X) return;
for (int idx = 0; idx < N; idx++) {
    local_X[idx] = X[idx * abs(incX)];
}
for (i = N - 1; i >= 0; i--) {
    double tmp = local_X[i];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    for (j = j_min; j < j_max; j++) {
        const double Aij = A[lda * i + (j - i)];
        tmp -= Aij * local_X[j];
    }
    if (nonunit) {
        local_X[i] = tmp / A[lda * i + 0];
    } else {
        local_X[i] = tmp;
    }
}
for (i = 0; i < N; i++) {
    X[i * abs(incX)] = local_X[N - 1 - i];
}
free(local_X);
ix = ((incX) > 0 ? 0 : (N - 1) * (-incX)) - N * incX;
}
