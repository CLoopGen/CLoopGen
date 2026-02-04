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
for (i = 0; i < N; i++) {
    local_X[i] = X[i * incX]; // Remove WAW and WAR on X during computation
}
for (i = 0; i < N; i++) {
    double tmp = local_X[i];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    for (j = j_min; j < j_max; j++) {
        const double Aij = A[lda * i + (K + j - i)];
        tmp -= Aij * local_X[j];
    }
    if (nonunit) {
        local_X[i] = tmp / A[lda * i + K];
    } else {
        local_X[i] = tmp;
    }
}
// Write back to X without loop-carried dependencies
int write_ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 0; i < N; i++) {
    X[write_ix] = local_X[i];
    write_ix += incX;
}
free(local_X);
}
