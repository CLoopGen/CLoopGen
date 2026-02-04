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
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) break;
    float tmp1_0 = alpha * X[ix];
    float tmp1_1 = alpha * X[ix + incX];
    float tmp2_0 = 0.0f, tmp2_1 = 0.0f;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min * incY;
    for (j = j_min; j < j_max; j++) {
        const float apk0 = Ap[((i * (2 * N - i + 1)) / 2 + j - i)];
        const float apk1 = (i+1 < j) ? Ap[(((i+1) * (2 * N - i)) / 2 + j - (i+1))] : 0.0f;
        Y[iy] += tmp1_0 * apk0;
        Y[iy + incY] += tmp1_1 * apk1;
        tmp2_0 += apk0 * X[jx];
        tmp2_1 += apk1 * X[jx];
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * tmp2_0;
    Y[iy + incY] += alpha * tmp2_1;
    ix += 2 * incX;
    iy += 2 * incY;
}
}
