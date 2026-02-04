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

    if (!(tmpR == 0. && tmpI == 0.)) {
        const int i_min = (j >= U ? j - U : 0);
        const int i_max = (lenY < j + L ? lenY : j + L);
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY)) + i_min * incY;

        if (i_min < i_max) {
            const int unroll_factor = 4;
            int i = i_min;
            int remainder = (i_max - i_min) % unroll_factor;
            
            for (int r = 0; r < remainder; r++, i++, iy += incY) {
                const double A_real = (((const double *)A)[2 * (lda * j + (U + i - j))]);
                const double A_imag = (((const double *)A)[2 * (lda * j + (U + i - j)) + 1]);
                (((double *)Y)[2 * (iy)]) += A_real * tmpR - (-A_imag) * tmpI;
                (((double *)Y)[2 * (iy) + 1]) += A_real * tmpI + (-A_imag) * tmpR;
            }

            for (; i <= i_max - unroll_factor; i += unroll_factor, iy += incY * unroll_factor) {
                const double A_real0 = (((const double *)A)[2 * (lda * j + (U + i - j))]);
                const double A_imag0 = (((const double *)A)[2 * (lda * j + (U + i - j)) + 1]);
                const double A_real1 = (((const double *)A)[2 * (lda * j + (U + i + 1 - j))]);
                const double A_imag1 = (((const double *)A)[2 * (lda * j + (U + i + 1 - j)) + 1]);
                const double A_real2 = (((const double *)A)[2 * (lda * j + (U + i + 2 - j))]);
                const double A_imag2 = (((const double *)A)[2 * (lda * j + (U + i + 2 - j)) + 1]);
                const double A_real3 = (((const double *)A)[2 * (lda * j + (U + i + 3 - j))]);
                const double A_imag3 = (((const double *)A)[2 * (lda * j + (U + i + 3 - j)) + 1]);

                (((double *)Y)[2 * (iy)]) += A_real0 * tmpR - (-A_imag0) * tmpI;
                (((double *)Y)[2 * (iy) + 1]) += A_real0 * tmpI + (-A_imag0) * tmpR;

                (((double *)Y)[2 * (iy + incY)]) += A_real1 * tmpR - (-A_imag1) * tmpI;
                (((double *)Y)[2 * (iy + incY) + 1]) += A_real1 * tmpI + (-A_imag1) * tmpR;

                (((double *)Y)[2 * (iy + 2*incY)]) += A_real2 * tmpR - (-A_imag2) * tmpI;
                (((double *)Y)[2 * (iy + 2*incY) + 1]) += A_real2 * tmpI + (-A_imag2) * tmpR;

                (((double *)Y)[2 * (iy + 3*incY)]) += A_real3 * tmpR - (-A_imag3) * tmpI;
                (((double *)Y)[2 * (iy + 3*incY) + 1]) += A_real3 * tmpI + (-A_imag3) * tmpR;
            }

            for (; i < i_max; i++, iy += incY) {
                const double A_real = (((const double *)A)[2 * (lda * j + (U + i - j))]);
                const double A_imag = (((const double *)A)[2 * (lda * j + (U + i - j)) + 1]);
                (((double *)Y)[2 * (iy)]) += A_real * tmpR - (-A_imag) * tmpI;
                (((double *)Y)[2 * (iy) + 1]) += A_real * tmpI + (-A_imag) * tmpR;
            }
        }
    }
    ix += incX;
}
}
