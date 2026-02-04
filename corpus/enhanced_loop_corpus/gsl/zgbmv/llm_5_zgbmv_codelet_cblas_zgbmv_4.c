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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j++) {
    const double x_real = (((const double *)X)[2 * (ix)]);
    const double x_imag = (((const double *)X)[2 * (ix) + 1]);
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    if (tmpR == 0. && tmpI == 0.) {
        ix += incX;
        continue;
    }
    const int i_min = (j >= U ? j - U : 0);
    const int i_max = (lenY <= j + L ? lenY : j + L + 1);
    int iy_start_offset = (incY > 0 ? 0 : (lenY - 1) * (-incY));
    int iy = iy_start_offset + i_min * incY;
    for (i = i_min; i < i_max; i++) {
        int A_index = 2 * (lda * j + (U + i - j));
        const double A_real = (((const double *)A)[A_index]);
        const double A_imag = (((const double *)A)[A_index + 1]);
        int Y_index = 2 * iy;
        double *y_ptr = &(((double *)Y)[Y_index]);
        y_ptr[0] += A_real * tmpR + A_imag * tmpI;
        y_ptr[1] += A_real * tmpI - A_imag * tmpR;
        iy += incY;
    }
    ix += incX;
}
}
