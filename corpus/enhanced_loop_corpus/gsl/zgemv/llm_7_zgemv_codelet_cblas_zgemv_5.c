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
// Reverse outer loop to introduce different loop-carried dependency pattern (backward traversal)
// This removes the natural forward loop-carried dependency and creates anti-dependence (WAR)
for (i = lenY - 1; i >= 0; i--) {
    double dotR = 0.;
    double dotI = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    // Unroll inner loop by factor of 2 if possible to reduce loop overhead and change data flow
    int j = 0;
    for (; j + 1 < lenX; j += 2) {
        // First element
        const double x_real1 = (((const double *)X)[2 * (ix)]);
        const double x_imag1 = (((const double *)X)[2 * (ix) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag1 = (((const double *)A)[2 * (lda * i + j) + 1]);
        dotR += A_real1 * x_real1 - (-A_imag1) * x_imag1;
        dotI += A_real1 * x_imag1 + (-A_imag1) * x_real1;
        ix += incX;

        // Second element
        const double x_real2 = (((const double *)X)[2 * (ix)]);
        const double x_imag2 = (((const double *)X)[2 * (ix) + 1]);
        const double A_real2 = (((const double *)A)[2 * (lda * i + j + 1)]);
        const double A_imag2 = (((const double *)A)[2 * (lda * i + j + 1) + 1]);
        dotR += A_real2 * x_real2 - (-A_imag2) * x_imag2;
        dotI += A_real2 * x_imag2 + (-A_imag2) * x_real2;
        ix += incX;
    }
    // Handle remaining element if lenX is odd
    for (; j < lenX; j++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        const double A_real = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag = (((const double *)A)[2 * (lda * i + j) + 1]);
        dotR += A_real * x_real - (-A_imag) * x_imag;
        dotI += A_real * x_imag + (-A_imag) * x_real;
        ix += incX;
    }
    // Accumulate result into Y using reversed index access
    (((double *)Y)[2 * (iy)]) += alpha_real * dotR - alpha_imag * dotI;
    (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI + alpha_imag * dotR;
    iy -= incY; // Note: now decrements to match reverse traversal assumption
}
}
