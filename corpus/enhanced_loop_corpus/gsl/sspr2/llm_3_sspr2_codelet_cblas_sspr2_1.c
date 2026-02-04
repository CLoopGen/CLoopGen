#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to indirect indexing using index arrays to support arbitrary access
// Simulate gather-style access via precomputed index vectors (within constraints of C and no heap)
int idx[N], idy[N];
int base_ix = (incX > 0 ? 0 : (N - 1) * (-incX));
int base_iy = (incY > 0 ? 0 : (N - 1) * (-incY));
for (int k = 0; k < N; k++) {
    idx[k] = base_ix + k * incX;
    idy[k] = base_iy + k * incY;
}
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    for (j = 0; j <= i; j++) {
        Ap[(i * (i + 1)) / 2 + j] += tmp1 * Y[idy[j]] + tmp2 * X[idx[j]];
    }
    ix += incX;
    iy += incY;
}
}
