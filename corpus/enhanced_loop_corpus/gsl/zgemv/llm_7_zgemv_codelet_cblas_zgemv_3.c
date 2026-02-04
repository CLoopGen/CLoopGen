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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < lenX; j++) {
        double x_real = (((const double *)X)[2 * ix]);
        double x_imag = (((const double *)X)[2 * ix + 1]);
        double tmpR = alpha_real * x_real - alpha_imag * x_imag;
        double tmpI = alpha_real * x_imag + alpha_imag * x_real;
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        // Introduce artificial loop-carried dependence via cumulative update
        double prev_real = 0.0, prev_imag = 0.0;
        for (i = 0; i < lenY; i++) {
            const double A_real = (((const double *)A)[2 * (lda * j + i)]);
            const double A_imag = (((const double *)A)[2 * (lda * j + i) + 1]);
            double computed_real = A_real * tmpR - A_imag * tmpI;
            double computed_imag = A_real * tmpI + A_imag * tmpR;
            // Create WAW and WAR dependency: use previous iteration's result
            double fused_real = computed_real + prev_real;
            double fused_imag = computed_imag + prev_imag;
            (((double *)Y)[2 * iy]) += fused_real;
            (((double *)Y)[2 * iy + 1]) += fused_imag;
            // Update prev for next iteration (loop-carried flow dependence)
            prev_real = fused_real;
            prev_imag = fused_imag;
            iy += incY;
        }
        ix += incX;
    }
}
