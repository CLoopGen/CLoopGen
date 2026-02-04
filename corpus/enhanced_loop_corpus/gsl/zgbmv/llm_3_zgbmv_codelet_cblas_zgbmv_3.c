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
    const ptrdiff_t x_index = 2 * ix;
    const double x_real = ((const double*)X)[x_index];
    const double x_imag = ((const double*)X)[x_index + 1];
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    if (!(tmpR == 0. && tmpI == 0.)) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        const int incY_abs = incY > 0 ? incY : -incY;
        int iy_base = (incY > 0 ? 0 : (lenY - 1) * incY_abs);
        for (i = i_min; i < i_max; i++) {
            const int packed_col = U + i - j;
            const ptrdiff_t A_index = 2 * (lda * j + packed_col);
            const ptrdiff_t Y_index = 2 * (iy_base + i * incY_abs);
            const double A_real = ((const double*)A)[A_index];
            const double A_imag = ((const double*)A)[A_index + 1];
            ((double*)Y)[Y_index] += A_real * tmpR - A_imag * tmpI;
            ((double*)Y)[Y_index + 1] += A_real * tmpI + A_imag * tmpR;
        }
    }
    ix += incX;
}
}
