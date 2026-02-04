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
extern double *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
const int unroll_factor = 4;
const int peeled_end = (N / unroll_factor) * unroll_factor;
for (i = 0; i < peeled_end; i += unroll_factor) {
    int base_ix = ix;
    int base_iy = iy;
    double temps1[unroll_factor];
    double temps2[unroll_factor];
    for (int u = 0; u < unroll_factor; u++) {
        temps1[u] = alpha * X[base_ix + u * incX];
        temps2[u] = alpha * Y[base_iy + u * incY];
    }
    for (j = i; j < N; j++) {
        int jx = ix;
        int jy = iy;
        for (int u = 0; u < unroll_factor; u++) {
            if (i + u < N) {
                const ptrdiff_t index = ((i + u) * (2 * N - (i + u) + 1)) / 2 + (j - (i + u));
                Ap[index] += temps1[u] * Y[jy] + temps2[u] * X[jx];
            }
        }
        jx += incX;
        jy += incY;
    }
    ix += unroll_factor * incX;
    iy += unroll_factor * incY;
}
// Handle remaining iterations
for (; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        const ptrdiff_t index = (i * (2 * N - i + 1)) / 2 + (j - i);
        Ap[index] += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
