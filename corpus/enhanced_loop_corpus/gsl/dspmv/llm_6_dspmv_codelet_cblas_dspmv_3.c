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
for (i = 0; i < N; i++) {
    double tmp1 = alpha * X[ix];
    double tmp2 = 0.;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    for (j = j_min; j < j_max; j++) {
        const double apk = Ap[(((i) * ((i) + 1)) / 2 + (j))];
        tmp2 += apk * X[jx];
        Y[jy] += tmp1 * apk;
        jy += incY;
        jx += incX;
    }
    Y[iy] += tmp1 * Ap[(((i) * ((i) + 1)) / 2 + (i))] + alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
