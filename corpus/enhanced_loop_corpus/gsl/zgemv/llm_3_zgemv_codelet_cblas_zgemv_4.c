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
const double* X_ptr = (const double*)X;
double* Y_ptr = (double*)Y;
const double* A_ptr = (const double*)A;
for (j = 0; j < lenX; j++) {
    int offset_x = 2 * ix;
    double x_real = X_ptr[offset_x];
    double x_imag = X_ptr[offset_x + 1];
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int base_y = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) * 2;
    for (i = 0; i < lenY; i++) {
        int idx_A = 2 * (lda * j + i);
        const double A_real = A_ptr[idx_A];
        const double A_imag = A_ptr[idx_A + 1];
        int idx_Y = base_y + 2 * i * incY;
        Y_ptr[idx_Y] += A_real * tmpR - (-A_imag) * tmpI;
        Y_ptr[idx_Y + 1] += A_real * tmpI + (-A_imag) * tmpR;
    }
    ix += incX;
}
}
