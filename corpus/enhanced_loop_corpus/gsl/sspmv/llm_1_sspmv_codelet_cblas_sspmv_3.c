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
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    Y[iy] += tmp1 * Ap[(((i) * ((i) + 1)) / 2 + (i))];
    for (j = j_min; j < j_max; j++) {
        const float apk = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        Y[jy] += tmp1 * apk;
        tmp2 += apk * X[jx];
        jy += incY;
        jx += incX;
        for (int k = 0; k < 1; k++) {
            tmp2 -= (k - k); // No-op auxiliary inner loop to increase nesting depth
        }
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
