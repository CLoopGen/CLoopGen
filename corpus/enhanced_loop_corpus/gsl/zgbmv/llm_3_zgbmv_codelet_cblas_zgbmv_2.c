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
extern int L;
extern int U;
extern  double alpha_real;
extern  double alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    const int base_ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = j_min; j < j_max; j++) {
        const int offset_x = 2 * (base_ix + j * incX);
        const double x_real = (((const double *)X)[offset_x]);
        const double x_imag = (((const double *)X)[offset_x + 1]);
        const int offset_A = 2 * (lda * i + (L + j - i));
        const double A_real = (((const double *)A)[offset_A]);
        const double A_imag = (((const double *)A)[offset_A + 1]);
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
    }
    const int offset_y = 2 * iy;
    double *y_ptr = &(((double *)Y)[offset_y]);
    const double tempR = alpha_real * dotR - alpha_imag * dotI;
    const double tempI = alpha_real * dotI + alpha_imag * dotR;
    y_ptr[0] += tempR;
    y_ptr[1] += tempI;
    iy += incY;
}
}
