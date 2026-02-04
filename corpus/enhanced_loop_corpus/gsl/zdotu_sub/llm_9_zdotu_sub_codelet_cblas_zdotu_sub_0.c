#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern double r_real;
extern double r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N && i < 64; i++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        const double y_real = (((const double *)Y)[2 * (iy)]);
        const double y_imag = (((const double *)Y)[2 * (iy) + 1]);

        // Reduced arithmetic: only accumulate real part with simplified operation
        r_real += x_real * y_real;
        // Skip imaginary accumulation entirely

        ix += incX;
        iy += incY;
    }
    // Introduce a second smaller loop to maintain some complexity balance
    for (int j = 0; j < N && N > 100 && j < 10; j++) {
        r_imag += (((const double *)Y)[2 * (j * incY)]) * 0.5;
    }
}
