#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern  double alpha_real;
extern  double alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse loop order to eliminate forward loop-carried dependencies and change memory access pattern
for (i = lenY - 1; i >= 0; i--) {
    double dotR = 0.;
    double dotI = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    // Unroll inner loop by factor of 2 (assuming lenX is even for simplicity) to expose more parallelism and modify data flow
    for (j = 0; j < lenX; j += 2) {
        // First iteration of unrolled loop
        const double x_real1 = (((const double *)X)[2 * (ix)]);
        const double x_imag1 = (((const double *)X)[2 * (ix) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag1 = (((const double *)A)[2 * (lda * i + j) + 1]);
        dotR += A_real1 * x_real1 - A_imag1 * x_imag1;
        dotI += A_real1 * x_imag1 + A_imag1 * x_real1;
        
        // Second iteration (if within bounds)
        if (j + 1 < lenX) {
            int ix_next = ix + incX;
            const double x_real2 = (((const double *)X)[2 * (ix_next)]);
            const double x_imag2 = (((const double *)X)[2 * (ix_next) + 1]);
            const double A_real2 = (((const double *)A)[2 * (lda * i + j + 1)]);
            const double A_imag2 = (((const double *)A)[2 * (lda * i + j + 1) + 1]);
            dotR += A_real2 * x_real2 - A_imag2 * x_imag2;
            dotI += A_real2 * x_imag2 + A_imag2 * x_real2;
            ix = ix_next + incX; // Advance twice
        } else {
            ix += incX;
        }
    }
    // Use temporary variables to remove immediate write-after-write (WAW) with prior iterations
    double new_real = alpha_real * dotR - alpha_imag * dotI;
    double new_imag = alpha_real * dotI + alpha_imag * dotR;
    (((double *)Y)[2 * (iy)]) += new_real;
    (((double *)Y)[2 * (iy) + 1]) += new_imag;
    iy += incY;
}
}
