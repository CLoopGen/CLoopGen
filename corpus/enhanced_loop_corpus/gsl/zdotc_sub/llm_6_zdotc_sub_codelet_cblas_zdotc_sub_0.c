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
    double temp_r_real = r_real;
    double temp_r_imag = r_imag;
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        const double x_real = (((const double *)X)[2 * (local_ix)]);
        const double x_imag = (((const double *)X)[2 * (local_ix) + 1]);
        const double y_real = (((const double *)Y)[2 * (local_iy)]);
        const double y_imag = (((const double *)Y)[2 * (local_iy) + 1]);
        temp_r_real += x_real * y_real - (-1.) * x_imag * y_imag;
        temp_r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
        local_ix += incX;
        local_iy += incY;
    }
    r_real = temp_r_real;
    r_imag = temp_r_imag;
    ix = local_ix;
    iy = local_iy;
}
