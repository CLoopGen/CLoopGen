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
    const int j_min = 0;
    const int j_max = i;
    int base_idx = (i * (i + 1)) / 2;
    int jx = 0;
    int jy = 0;
    Y[iy] += tmp1 * Ap[base_idx + i];
    for (j = j_min; j < j_max; j++) {
        const float apk = Ap[base_idx + j];
        int index_y = jy + j * incY;
        int index_x = jx + j * incX;
        Y[index_y] += tmp1 * apk;
        tmp2 += apk * X[index_x];
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
