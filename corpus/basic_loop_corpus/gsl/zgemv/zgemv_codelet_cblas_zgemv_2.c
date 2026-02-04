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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        const double A_real = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag = (((const double *)A)[2 * (lda * i + j) + 1]);
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
        ix += incX;
    }
    (((double *)Y)[2 * (iy)]) += alpha_real * dotR - alpha_imag * dotI;
    (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}

}
