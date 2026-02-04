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
double *restrict Y_ptr = (double *)Y;
const double *restrict A_ptr = (const double *)A;
const double *restrict X_ptr = (const double *)X;
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double x_real = X_ptr[2 * ix];
        const double x_imag = X_ptr[2 * ix + 1];
        const double A_real = A_ptr[2 * (lda * i + (L + j - i))];
        const double A_imag = A_ptr[2 * (lda * i + (L + j - i)) + 1];
        double prodR = A_real * x_real + A_imag * x_imag;
        double prodI = A_real * x_imag - A_imag * x_real;
        dotR += prodR;
        dotI += prodI;
        ix += incX;
    }
    int y_idx = 2 * iy;
    Y_ptr[y_idx]     += alpha_real * dotR - alpha_imag * dotI;
    Y_ptr[y_idx + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
