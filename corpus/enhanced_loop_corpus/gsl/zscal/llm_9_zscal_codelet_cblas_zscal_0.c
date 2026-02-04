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
        const double x_real = (((double *)X)[2 * (ix)]);
        const double x_imag = (((double *)X)[2 * (ix) + 1]);

        double temp_real = x_real * alpha_real - x_imag * alpha_imag;
        double temp_imag = x_real * alpha_imag + x_imag * alpha_real;

        // Additional computational workload: simulate a light filtering effect
        temp_real = (temp_real + (((double *)X)[2 * (ix)]) * 0.1) / 1.1;
        temp_imag = (temp_imag + (((double *)X)[2 * (ix) + 1]) * 0.1) / 1.1;

        (((double *)X)[2 * (ix)]) = temp_real;
        (((double *)X)[2 * (ix) + 1]) = temp_imag;

        ix += incX;
    }
}
