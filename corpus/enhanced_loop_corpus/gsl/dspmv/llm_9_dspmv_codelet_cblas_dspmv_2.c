#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *Ap;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) break;
    double tmp1_0 = alpha * X[ix];
    double tmp1_1 = alpha * X[ix + incX];
    double tmp2_0 = 0.;
    double tmp2_1 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    for (j = j_min; j < j_max; j++) {
        const double apk = Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))];
        const double apk_next = Ap[((((((i+1) - 1) + 1) * (2 * (N) - ((i+1) - 1))) / 2) + (j) - (i+1))];
        Y[jy] += tmp1_0 * apk;
        Y[jy] += tmp1_1 * apk_next;
        tmp2_0 += apk * X[jx];
        tmp2_1 += apk_next * X[jx];
        jy += incY;
    }
    Y[iy] += alpha * tmp2_0;
    Y[iy + incY] += alpha * tmp2_1;
    ix += 2 * incX;
    iy += 2 * incY;
}
}
