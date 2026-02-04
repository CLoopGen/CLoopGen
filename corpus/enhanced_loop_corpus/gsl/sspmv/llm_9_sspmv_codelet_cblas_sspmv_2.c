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
    const int j_min = i + 1;
    const int j_max = (N + i) / 2;  // Reduced trip count in inner loop
    int jx = ((incX > 0) ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = ((incY > 0) ? 0 : (N - 1) * (-incY)) + j_min * incY;
    Y[iy] += tmp1 * Ap[(i * (2 * N - i + 1)) / 2];  // Simplified index calculation
    for (j = j_min; j < j_max; j++) {
        const float apk = Ap[(i * (2 * N - i + 1)) / 2 + j - i];
        Y[jy] += tmp1 * apk;
        tmp2 += apk * X[jx];
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
