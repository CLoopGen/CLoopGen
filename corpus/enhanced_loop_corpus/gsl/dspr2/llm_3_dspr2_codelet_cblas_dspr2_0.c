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
const int stride_x = incX * sizeof(double);
const int stride_y = incY * sizeof(double);
double *baseX = X;
double *baseY = Y;
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * baseX[ix / sizeof(double)];
    const double tmp2 = alpha * baseY[iy / sizeof(double)];
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        int index = ((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2 + (j) - (i);
        Ap[index] += tmp1 * baseY[jy / sizeof(double)] + tmp2 * baseX[jx / sizeof(double)];
        jx += stride_x;
        jy += stride_y;
    }
    ix += incX;
    iy += incY;
}
}
