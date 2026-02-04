#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Consecutive memory access by precomputing and storing effective indices
int* x_indices = (int*)malloc(N * sizeof(int));
int base_x = ((incX) > 0 ? 0 : (N - 1) * (-incX));
for (int k = 0; k < N; k++) {
    x_indices[k] = base_x + k * incX;
}

ix = x_indices[1]; // Start from index corresponding to i=1
for (i = 1; i < N; i++) {
    double tmp = X[ix];
    for (j = 0; j < i; j++) {
        const double Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (i) - (j))];
        tmp -= Aji * X[x_indices[j]];
    }
    if (nonunit) {
        X[ix] = tmp / Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (i) - (i))];
    } else {
        X[ix] = tmp;
    }
    ix = x_indices[i + 1 < N ? i + 1 : i]; // Update ix using precomputed indices
}
free(x_indices);
}
