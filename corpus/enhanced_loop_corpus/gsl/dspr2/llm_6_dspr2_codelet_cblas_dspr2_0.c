#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    double temp_acc = 0.0;
    for (j = i; j < N; j++) {
        temp_acc += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
    Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (N-1) - (i))] += temp_acc;
    ix += incX;
    iy += incY;
}
}
