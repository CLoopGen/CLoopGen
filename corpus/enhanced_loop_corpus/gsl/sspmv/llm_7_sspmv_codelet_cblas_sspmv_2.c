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
float temp_accum = 0.0;
for (i = 0; i < N; i++) {
    float local_tmp = alpha * X[ix];
    temp_accum += local_tmp;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX > 0) ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy = ((incY > 0) ? 0 : (N - 1) * (-incY)) + j_min * incY;
    for (j = j_min; j < j_max; j++) {
        const float apk = Ap[((i * (2 * N - i + 1)) / 2) + (j - i)];
        Y[jy] += local_tmp * apk;
        jy += incY;
        jx += incX;
    }
    Y[iy] += temp_accum * X[ix];
    ix += incX;
    iy += incY;
}
}
