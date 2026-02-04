#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_A = A;
    const double local_alpha = alpha;
    const int local_M = M, local_N = N;
    const int local_incX = incX, local_incY = incY;
    const double *local_X = X, *local_Y = Y;
    const int local_lda = lda;

    int local_ix = ix;
    for (i = 0; i < local_M; i++) {
        double x_val = local_X[local_ix];
        double scaled_x = local_alpha * x_val;
        int jy = (local_incY > 0 ? 0 : (local_N - 1) * (-local_incY));
        for (j = 0; j < local_N; j++) {
            local_A[local_lda * i + j] = scaled_x * local_Y[jy] + local_A[local_lda * i + j];
            jy += local_incY;
        }
        local_ix += local_incX;
    }
    ix = local_ix;
}
