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
    double prev_y_real = 0.0, prev_y_imag = 0.0;
    for (i = 0; i < N; i++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        double current_y_real = (((double *)Y)[2 * (iy)]);
        double current_y_imag = (((double *)Y)[2 * (iy) + 1]);

        double computed_real = alpha_real * x_real - alpha_imag * x_imag;
        double computed_imag = alpha_real * x_imag + alpha_imag * x_real;

        if (i > 0) {
            computed_real += prev_y_real;
            computed_imag += prev_y_imag;
        }

        (((double *)Y)[2 * (iy)]) = current_y_real + computed_real;
        (((double *)Y)[2 * (iy) + 1]) = current_y_imag + computed_imag;

        prev_y_real = computed_real;
        prev_y_imag = computed_imag;

        ix += incX;
        iy += incY;
    }
}
