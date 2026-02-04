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
for (i = 0; i < N; i += 2) {
    const double x_real1 = (((const double *)X)[2 * (ix)]);
    const double x_imag1 = (((const double *)X)[2 * (ix) + 1]);
    const double y_real1 = (((const double *)Y)[2 * (iy)]);
    const double y_imag1 = (((const double *)Y)[2 * (iy) + 1]);
    
    r_real += x_real1 * y_real1 - (-1.) * x_imag1 * y_imag1;
    r_imag += x_real1 * y_imag1 + (-1.) * x_imag1 * y_real1;
    
    ix += incX;
    iy += incY;

    if (i + 1 < N) {
        const double x_real2 = (((const double *)X)[2 * (ix)]);
        const double x_imag2 = (((const double *)X)[2 * (ix) + 1]);
        const double y_real2 = (((const double *)Y)[2 * (iy)]);
        const double y_imag2 = (((const double *)Y)[2 * (iy) + 1]);

        r_real += x_real2 * y_real2 - (-1.) * x_imag2 * y_imag2;
        r_imag += x_real2 * y_imag2 + (-1.) * x_imag2 * y_real2;

        ix += incX;
        iy += incY;
    }
}
}
