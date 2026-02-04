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
    float tmp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = j_min * incX;
    int jy = j_min * incY;
    if (incX < 0) jx = (N - 1) * (-incX) + j_min * incX;
    if (incY < 0) jy = (N - 1) * (-incY) + j_min * incY;

    // Force consecutive memory access by precomputing base offsets and using unit stride
    int ap_base = ((((i) - 1) + 1) * (2 * N - ((i) - 1))) / 2 - i;
    Y[iy] += tmp1 * Ap[ap_base + i];

    for (j = j_min; j < j_max; j++) {
        int ap_index = ap_base + j;
        const float apk = Ap[ap_index];
        Y[jy] += tmp1 * apk;
        tmp2 += apk * X[jx];
        jy += incY;
        jx += incX;
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
