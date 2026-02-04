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
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i; j += 2) {
        if (j + 1 <= i) {
            // Process two elements per iteration to increase computational intensity
            Ap[(((i) * ((i) + 1)) / 2 + (j))]     += tmp1 * Y[jy] + tmp2 * X[jx];
            Ap[(((i) * ((i) + 1)) / 2 + (j + 1))] += tmp1 * Y[jy + incY] + tmp2 * X[jx + incX];
            jx += 2 * incX;
            jy += 2 * incY;
        } else {
            // Handle odd-sized rows
            Ap[(((i) * ((i) + 1)) / 2 + (j))] += tmp1 * Y[jy] + tmp2 * X[jx];
        }
    }
    ix += incX;
    iy += incY;
}
}
