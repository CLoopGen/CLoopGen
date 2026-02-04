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
for (i = 0; i < N; i += 2) {
    const double tmp1a = alpha * X[ix];
    const double tmp2a = alpha * Y[iy];
    const double tmp1b = (i+1 < N) ? alpha * X[ix + incX] : 0.0;
    const double tmp2b = (i+1 < N) ? alpha * Y[iy + incY] : 0.0;
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        const ptrdiff_t index = (((i) * (2 * N - i + 1)) / 2) + (j - i);
        Ap[index] += tmp1a * Y[jy] + tmp2a * X[jx];
        if (i+1 < N) {
            const ptrdiff_t index_next = ((((i+1) * (2 * N - (i+1) + 1)) / 2)) + (j - i - 1);
            if (j >= i+1) {
                Ap[index_next] += tmp1b * Y[jy] + tmp2b * X[jx];
            }
        }
        jx += incX;
        jy += incY;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
