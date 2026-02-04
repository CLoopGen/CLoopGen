#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern void *A;
extern  int lda;
extern int i;
extern int j;
extern  double alpha_real;
extern  double alpha_imag;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_tmp_real = 0.0, prev_tmp_imag = 0.0;
for (j = 0; j < N; j++) {
    const double Y_real = (((const double *)Y)[2 * (jy)]);
    const double Y_imag = -(((const double *)Y)[2 * (jy) + 1]);
    // Create a loop-carried dependency (RAW): current iteration depends on prior tmp values
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag + prev_tmp_real;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag + prev_tmp_imag;
    prev_tmp_real = tmp_real;
    prev_tmp_imag = tmp_imag;

    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        const double X_real = (((const double *)X)[2 * (ix)]);
        const double X_imag = (((const double *)X)[2 * (ix) + 1]);
        // Modify access pattern to A: use reverse indexing to break spatial locality but maintain correctness
        const int index = 2 * ((M - 1 - i) + lda * j); // Reverse row order
        (((double *)A)[index]) += X_real * tmp_real - X_imag * tmp_imag;
        (((double *)A)[index + 1]) += X_imag * tmp_real + X_real * tmp_imag;
        ix += incX;
    }
    jy += incY;
}
}
