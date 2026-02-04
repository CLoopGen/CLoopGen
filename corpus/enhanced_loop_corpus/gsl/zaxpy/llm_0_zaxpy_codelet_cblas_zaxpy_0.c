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
    for (int k = 0; k < N / 2; k++) {
        for (int j = 0; j < 2; j++) {
            const int i = 2 * k + j;
            if (i >= N) break;
            const double x_real = (((const double *)X)[2 * (ix)]);
            const double x_imag = (((const double *)X)[2 * (ix) + 1]);
            (((double *)Y)[2 * (iy)]) += (alpha_real * x_real - alpha_imag * x_imag);
            (((double *)Y)[2 * (iy) + 1]) += (alpha_real * x_imag + alpha_imag * x_real);
            ix += incX;
            iy += incY;
        }
    }
}
