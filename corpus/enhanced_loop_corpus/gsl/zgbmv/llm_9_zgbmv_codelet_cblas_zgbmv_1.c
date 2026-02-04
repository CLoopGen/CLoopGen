#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY * 2; i++) {
    const int idx = (i % lenY);
    const int current_iy = idx * incY;
    const double y_real = (((double *)Y)[2 * current_iy]);
    const double y_imag = (((double *)Y)[2 * current_iy + 1]);

    double acc_real = y_real;
    double acc_imag = y_imag;

    for (int j = 0; j < 3; j++) {
        acc_real = acc_real * beta_real - acc_imag * beta_imag;
        acc_imag = y_real * beta_imag + y_imag * beta_real;
    }

    (((double *)Y)[2 * current_iy]) = acc_real;
    (((double *)Y)[2 * current_iy + 1]) = acc_imag;
}
}
