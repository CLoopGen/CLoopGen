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
    double temp_real, temp_imag;
    for (i = 0; i < N; i++) {
        const ptrdiff_t offset = 2 * ix;
        const double x_real = ((double *)X)[offset];
        const double x_imag = ((double *)X)[offset + 1];

        // Introduce temporary variables to break direct WAW and WAR dependencies
        // by deferring write until both computations are done (removes partial WAW)
        temp_real = x_real * alpha_real - x_imag * alpha_imag;
        temp_imag = x_real * alpha_imag + x_imag * alpha_real;

        ((double *)X)[offset]     = temp_real;
        ((double *)X)[offset + 1] = temp_imag;

        ix += incX;
    }
}
