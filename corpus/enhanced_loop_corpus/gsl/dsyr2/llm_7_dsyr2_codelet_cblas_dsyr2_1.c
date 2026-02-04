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
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_alpha_x = 0.0;
for (i = 0; i < N; i++) {
    double current_x_val = (incX != 0) ? X[ix] : 0.0;
    const double tmp1 = alpha * current_x_val + prev_alpha_x;
    const double tmp2 = alpha * Y[iy];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i; j++) {
        double update_val = tmp1 * Y[jy] + tmp2 * X[jx];
        A[lda * j + i] += update_val;
        jx += incX;
        jy += incY;
    }
    prev_alpha_x = alpha * current_x_val;
    ix += incX;
    iy += incY;
}
}
