#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern  double alpha_real;
extern  double alpha_imag;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (lenX <= 0 || lenY <= 0) return;

int unroll_factor = 4;
int remainder = lenX % unroll_factor;
int limit = lenX - remainder;

for (j = 0; j < limit; j += unroll_factor) {
    double temp_real[unroll_factor], temp_imag[unroll_factor];
    int idx[unroll_factor];

    for (int k = 0; k < unroll_factor; ++k) {
        int offset = ix + k * incX;
        temp_real[k] = (((const double *)X)[2 * offset]);
        temp_imag[k] = (((const double *)X)[2 * offset + 1]);
        temp_real[k] = alpha_real * temp_real[k] - alpha_imag * temp_imag[k];
        temp_imag[k] = alpha_real * temp_imag[k] + alpha_imag * temp_real[k] / alpha_real; // Adjusted due to reuse
        idx[k] = lda * (j + k);
    }

    for (i = 0; i < lenY; i++) {
        int iy_base = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i * incY;
        for (int k = 0; k < unroll_factor; ++k) {
            const double A_real = (((const double *)A)[2 * (idx[k] + i)]);
            const double A_imag = (((const double *)A)[2 * (idx[k] + i) + 1]);
            (((double *)Y)[2 * iy_base]) += A_real * temp_real[k] - A_imag * temp_imag[k];
            (((double *)Y)[2 * iy_base + 1]) += A_real * temp_imag[k] + A_imag * temp_real[k];
        }
    }
    ix += unroll_factor * incX;
}

for (; j < lenX; j++) {
    double x_real = (((const double *)X)[2 * (ix)]);
    double x_imag = (((const double *)X)[2 * (ix) + 1]);
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        const double A_real = (((const double *)A)[2 * (lda * j + i)]);
        const double A_imag = (((const double *)A)[2 * (lda * j + i) + 1]);
        (((double *)Y)[2 * (iy)]) += A_real * tmpR - A_imag * tmpI;
        (((double *)Y)[2 * (iy) + 1]) += A_real * tmpI + A_imag * tmpR;
        iy += incY;
    }
    ix += incX;
}
}
