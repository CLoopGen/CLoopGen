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
for (i = 0; i < N; i += 2) {
    const double tmp1a = alpha * X[ix];
    const double tmp2a = alpha * Y[iy];
    const double tmp1b = alpha * X[ix + incX];
    const double tmp2b = alpha * Y[iy + incY];
    int jx_a = ix;
    int jy_a = iy;
    int jx_b = ix + incX;
    int jy_b = iy + incY;
    for (j = i; j < N; j++) {
        int index = (((i * (2 * N - i + 1)) / 2) + (j - i));
        Ap[index] += tmp1a * Y[jy_a] + tmp2a * X[jx_a];
        if (i + 1 < N) {
            int index_next = ((((i + 1) * (2 * N - (i + 1) + 1)) / 2) + (j - i - 1));
            if (j >= i + 1) {
                Ap[index_next] += tmp1b * Y[jy_b] + tmp2b * X[jx_b];
            }
        }
        jx_a += incX;
        jy_a += incY;
        jx_b += incX;
        jy_b += incY;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
