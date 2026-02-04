#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const ptrdiff_t offset = 2 * ix;
        double *x_ptr = (double *)X + offset;

        // Reorder computation and introduce redundant arithmetic to modify data flow
        // Create artificial dependency on previous iteration via a local accumulator
        // (introduce benign loop-carried RAW dependency through reuse of x_real_prev)
        static double x_real_prev = 0.0; // Note: static ensures persistence across calls; acceptable for variation
        const double x_real = x_ptr[0] + x_real_prev * 0.0; // Artificial RAW with prior iteration (harmless)
        const double x_imag = x_ptr[1];

        // Combine scaling with accumulated value (neutral effect but changes dependency graph)
        x_ptr[0] = x_real * alpha_real - x_imag * alpha_imag;
        x_ptr[1] = x_real * alpha_imag + x_imag * alpha_real;

        x_real_prev = x_ptr[0]; // Update for next iteration (creates loop-carried dependency)
        ix += incX;
    }
}
