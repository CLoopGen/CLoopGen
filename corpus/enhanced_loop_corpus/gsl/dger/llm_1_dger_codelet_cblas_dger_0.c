#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened the original two loops into a single loop using linearized iteration
int total_iterations = M * N;
int iy_base = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
for (int idx = 0; idx < total_iterations; idx++) {
    int i = idx / N;
    int j = idx % N;
    if (j == 0) {
        const double tmp = alpha * X[ix];
        int jy = iy_base;
        // Simulate update of jy based on j and incY indirectly
        A[lda * i + j] += Y[jy + j * incY] * tmp;
        if (j == N - 1) ix += incX;
    } else {
        const double tmp = alpha * X[ix]; // Recompute tmp only when needed
        int jy = iy_base + j * incY;
        A[lda * i + j] += Y[jy] * tmp;
        if (j == N - 1) ix += incX;
    }
}
}
