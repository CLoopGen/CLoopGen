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
double prev_real = 0.0, prev_imag = 0.0;
for (i = 0; i < N; i++) {
    const int idx = 2 * iy;
    const double y_real = ((double *)Y)[idx];
    const double y_imag = ((double *)Y)[idx + 1];

    const double adjusted_beta_real = beta_real + (i > 0 ? prev_real * 0.1 : 0.0);
    const double adjusted_beta_imag = beta_imag + (i > 0 ? prev_imag * 0.1 : 0.0);

    const double tmpR = y_real * adjusted_beta_real - y_imag * adjusted_beta_imag;
    const double tmpI = y_real * adjusted_beta_imag + y_imag * adjusted_beta_real;

    ((double *)Y)[idx] = tmpR;
    ((double *)Y)[idx + 1] = tmpI;

    prev_real = tmpR;
    prev_imag = tmpI;
    iy += incY;
}
}
