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
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to indirect via index arrays
// Simulate indirect access using precomputed index vectors for X and Y
int *idx_X = (int*)malloc(N * sizeof(int));
int *idx_Y = (int*)malloc(N * sizeof(int));
int base_x = (incX > 0) ? 0 : (N - 1) * (-incX);
int base_y = (incY > 0) ? 0 : (N - 1) * (-incY);
for (int k = 0; k < N; k++) {
    idx_X[k] = base_x + k * incX;
    idx_Y[k] = base_y + k * incY;
}
for (i = 0; i < N; i++) {
    const float tmp1 = alpha * X[ix];
    const float tmp2 = alpha * Y[iy];
    for (j = 0; j <= i; j++) {
        A[lda * i + j] += tmp1 * Y[idx_Y[j]] + tmp2 * X[idx_X[j]];
    }
    ix += incX;
    iy += incY;
}
free(idx_X);
free(idx_Y);
}
