#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to enforce unit-stride (consecutive) access for A and reorganize X/Y indexing
// by precomputing effective indices to promote potential vectorization
int *idxX = (int*)alloca(N * sizeof(int));
int *idxY = (int*)alloca(N * sizeof(int));
int base_x = (incX > 0) ? 0 : (N - 1) * (-incX);
int base_y = (incY > 0) ? 0 : (N - 1) * (-incY);
for (int k = 0; k < N; k++) {
    idxX[k] = base_x + k * incX;
    idxY[k] = base_y + k * incY;
}

ix = (incX > 0) ? 0 : (N - 1) * (-incX);
iy = (incY > 0) ? 0 : (N - 1) * (-incY);

for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    for (j = 0; j <= i; j++) {
        // Use precomputed indices for strided arrays to convert indirect access into a more predictable pattern
        A[i * lda + j] += tmp1 * Y[idxY[j]] + tmp2 * X[idxX[j]];
    }
    ix += incX;
    iy += incY;
}
}
