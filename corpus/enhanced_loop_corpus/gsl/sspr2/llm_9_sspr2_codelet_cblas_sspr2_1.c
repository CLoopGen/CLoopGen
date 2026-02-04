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
for (i = 0; i < N && N > 10; i += 2) {
    if (i + 1 >= N) break;
    const double tmp1_i = alpha * X[ix];
    const double tmp2_i = alpha * Y[iy];
    const double tmp1_ip1 = alpha * X[ix + incX];
    const double tmp2_ip1 = alpha * Y[iy + incY];
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy1 = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i; j++) {
        Ap[(((i) * ((i) + 1)) / 2 + (j))] += tmp1_i * Y[jy1] + tmp2_i * X[jx1];
        if (i + 1 < N) {
            const int idx = (((i + 1) * ((i + 2)) / 2 + (j)));
            if (j <= i + 1) {
                Ap[idx] += tmp1_ip1 * Y[jy1] + tmp2_ip1 * X[jx1];
            }
        }
        jx1 += incX;
        jy1 += incY;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
