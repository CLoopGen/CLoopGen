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
if (N <= 0) return;
const int unroll_factor = 4;
int limit = N - (N % unroll_factor);
for (i = 0; i < limit; i += unroll_factor) {
    double tmp1[unroll_factor], tmp2[unroll_factor];
    int offsets[unroll_factor];
    int base_ix = ix;
    int base_iy = iy;
    for (int u = 0; u < unroll_factor; u++) {
        tmp1[u] = alpha * X[base_ix + u * incX];
        tmp2[u] = alpha * Y[base_iy + u * incY];
        offsets[u] = ((u + i) * (2 * N - (u + i) + 1)) / 2;
    }
    for (j = i; j < N; j++) {
        int jx = ix;
        int jy = iy;
        for (int u = 0; u < unroll_factor && (i + u) < N; u++) {
            int index = offsets[u] + (j - i - u);
            Ap[index] += tmp1[u] * Y[jy] + tmp2[u] * X[jx];
            jx += incX;
            jy += incY;
        }
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
        Ap[((i * (2 * N - i + 1)) / 2) + (j - i)] += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
