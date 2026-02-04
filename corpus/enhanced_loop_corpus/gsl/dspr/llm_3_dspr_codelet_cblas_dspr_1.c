#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Consecutive memory access by precomputing and storing transformed indices
int *index_map = (int*)malloc(N * sizeof(int));
int base = ((incX) > 0 ? 0 : (N - 1) * (-incX));
for (int k = 0; k < N; k++) {
    index_map[k] = base + k * incX;
}

ix = base;
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    for (j = 0; j <= i; j++) {
        Ap[(i * (i + 1)) / 2 + j] += X[index_map[j]] * tmp;
    }
    ix += incX;
}
free(index_map);
}
