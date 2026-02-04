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
    index_map[idx] = idx * incX; // Precompute indirect indices for strided access
}
for (i = 1; i < N; i++) {
    double tmp = X[ix];
    for (j = 0; j < i; j++) {
        const double Aji = A[lda * j + i];
        tmp -= Aji * X[index_map[j]]; // Indirect access using precomputed index array
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
