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
    double prev_tmpR = 0.0, prev_tmpI = 0.0;
    for (i = 0; i < N; i++) {
        const double y_real = (((double *)Y)[2 * (iy)]);
        const double y_imag = (((double *)Y)[2 * (iy) + 1]);
        const double tmpR = y_real * beta_real - y_imag * beta_imag + prev_tmpR;
        const double tmpI = y_real * beta_imag + y_imag * beta_real + prev_tmpI;
        (((double *)Y)[2 * (iy)]) = tmpR;
        (((double *)Y)[2 * (iy) + 1]) = tmpI;
        prev_tmpR = tmpR;
        prev_tmpI = tmpI;
        iy += incY;
    }
}
