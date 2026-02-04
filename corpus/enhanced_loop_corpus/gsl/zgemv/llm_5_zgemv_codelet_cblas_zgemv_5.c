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
for (i = 0; i < lenY; ++i) {
    double dotR = 0.0;
    double dotI = 0.0;
    int ix_start = (incX > 0) ? 0 : (lenX - 1) * (-incX);
    int j_end = lenX;
    for (j = 0; j < j_end; j++) {
        int offset_X = 2 * ix_start;
        int offset_A = 2 * (lda * i + j);
        const double x_real = ((const double*)X)[offset_X];
        const double x_imag = ((const double*)X)[offset_X + 1];
        const double A_real = ((const double*)A)[offset_A];
        const double A_imag = ((const double*)A)[offset_A + 1];
        if (!(j % 2)) {
            dotR += A_real * x_real + A_imag * x_imag;
            dotI += A_real * x_imag - A_imag * x_real;
        } else {
            dotR += x_real * A_real - x_imag * A_imag;
            dotI += x_real * A_imag + x_imag * A_real;
        }
        ix_start += incX;
    }
    int y_idx = 2 * iy;
    double Yr = ((double*)Y)[y_idx];
    double Yi = ((double*)Y)[y_idx + 1];
    ((double*)Y)[y_idx] = Yr + alpha_real * dotR - alpha_imag * dotI;
    ((double*)Y)[y_idx + 1] = Yi + alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
