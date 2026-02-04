#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using array indexing with fixed step and unrolling by 2 for better vectorization potential
    const double *x_base = (const double *)X;
    double *y_base = (double *)Y;
    const int x_step = 2 * incX;
    const int y_step = 2 * incY;

    // Unroll by 2 to expose more parallelism and improve cache utilization
    for (i = 0; i < N; i += 2) {
        // First element
        const double x_real1 = ((const double *)X)[ix];
        const double x_imag1 = ((const double *)X)[ix + 1];
        ((double *)Y)[iy] += (alpha_real * x_real1 - alpha_imag * x_imag1);
        ((double *)Y)[iy + 1] += (alpha_real * x_imag1 + alpha_imag * x_real1);

        // Second element (if within bounds)
        if (i + 1 < N) {
            const int ix_next = ix + x_step;
            const int iy_next = iy + y_step;
            const double x_real2 = ((const double *)X)[ix_next];
            const double x_imag2 = ((const double *)X)[ix_next + 1];
            ((double *)Y)[iy_next] += (alpha_real * x_real2 - alpha_imag * x_imag2);
            ((double *)Y)[iy_next + 1] += (alpha_real * x_imag2 + alpha_imag * x_real2);

            ix = ix_next + x_step; // Advance for next iteration
            iy = iy_next + y_step;
        } else {
            ix += x_step;
            iy += y_step;
        }
    }
}
