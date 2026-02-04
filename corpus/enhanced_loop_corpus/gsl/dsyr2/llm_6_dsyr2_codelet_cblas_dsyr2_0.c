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
    double *local_A = A;
    const double local_alpha = alpha;
    const int local_N = N;
    const int local_lda = lda;
    const int local_incX = incX;
    const int local_incY = incY;
    double *local_X = X;
    double *local_Y = Y;

    for (i = 0; i < local_N; i++) {
        const double xi = local_X[ix];
        const double yi = local_Y[iy];
        const double tmp1 = local_alpha * xi;
        const double tmp2 = local_alpha * yi;
        int jx = ix;
        int jy = iy;

        for (j = i; j < local_N; j++) {
            double update = tmp1 * local_Y[jy] + tmp2 * local_X[jx];
            local_A[local_lda * i + j] += update;
            jx += local_incX;
            jy += local_incY;
        }
        ix += local_incX;
        iy += local_incY;
    }
}
