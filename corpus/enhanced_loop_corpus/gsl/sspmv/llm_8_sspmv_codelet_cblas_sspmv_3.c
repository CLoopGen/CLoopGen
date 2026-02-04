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
for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.0f;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min * incY;
    Y[iy] += tmp1 * Ap[(i * (i + 1)) / 2 + i];
    for (j = j_min; j < j_max; j += 2) {
        const float apk0 = Ap[(i * (i + 1)) / 2 + j];
        Y[jy] += tmp1 * apk0;
        tmp2 += apk0 * X[jx];
        jy += incY;
        jx += incX;
        if (j + 1 < j_max) {
            const float apk1 = Ap[(i * (i + 1)) / 2 + j + 1];
            Y[jy] += tmp1 * apk1;
            tmp2 += apk1 * X[jx];
            jy += incY;
            jx += incX;
        }
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
