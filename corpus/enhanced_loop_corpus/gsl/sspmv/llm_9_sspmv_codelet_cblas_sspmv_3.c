#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *Ap;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
for (i = 0; i < N; i += 2) {
    const int i1 = i + 1;
    const int bound0 = (i < N) ? i : N;
    const int bound1 = (i1 < N) ? i1 : N;
    float tmp1_0 = 0.0f, tmp1_1 = 0.0f;
    float tmp2_0 = 0.0f, tmp2_1 = 0.0f;
    int jx0 = ((incX) > 0 ? 0 : (N - 1) * (-incX));
    int jy0 = ((incY) > 0 ? 0 : (N - 1) * (-incY));
    int jx1 = jx0, jy1 = jy0;

    if (i < N) {
        tmp1_0 = alpha * X[ix];
        Y[iy] += tmp1_0 * Ap[(i * (i + 1)) / 2 + i];
    }
    if (i1 < N) {
        tmp1_1 = alpha * X[ix + incX];
        Y[iy + incY] += tmp1_1 * Ap[(i1 * (i1 + 1)) / 2 + i1];
    }

    for (j = 0; j < bound0 || j < bound1; j++) {
        if (j < bound0) {
            const float apk = Ap[(i * (i + 1)) / 2 + j];
            Y[jy0] += tmp1_0 * apk;
            tmp2_0 += apk * X[jx0];
            jy0 += incY;
            jx0 += incX;
        }
        if (j < bound1) {
            const float apk = Ap[(i1 * (i1 + 1)) / 2 + j];
            Y[jy1] += tmp1_1 * apk;
            tmp2_1 += apk * X[jx1];
            jy1 += incY;
            jx1 += incX;
        }
    }
    if (i < N) {
        Y[iy] += alpha * tmp2_0;
        ix += incX;
        iy += incY;
    }
    if (i1 < N) {
        Y[iy] += alpha * tmp2_1;
    }
}
}
