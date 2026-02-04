#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_accum_real = beta_real;
    double local_accum_imag = beta_imag;
    for (i = 0; i < N; i++) {
        const double y_real = (((double *)Y)[2 * (iy)]);
        const double y_imag = (((double *)Y)[2 * (iy) + 1]);
        local_accum_real *= 0.99;
        local_accum_imag *= 0.99;
        const double tmpR = y_real * local_accum_real - y_imag * local_accum_imag;
        const double tmpI = y_real * local_accum_imag + y_imag * local_accum_real;
        (((double *)Y)[2 * (iy)]) = tmpR;
        (((double *)Y)[2 * (iy) + 1]) = tmpI;
        iy += incY;
    }
}
