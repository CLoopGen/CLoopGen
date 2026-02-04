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
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy_start = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        int stride = incY;

        for (i = i_min; i < i_max; i += 2) {
            int iy = iy_start + (i - i_min) * stride;
            const double A_real1 = (((const double *)A)[2 * (lda * j + (U + i - j))]);
            const double A_imag1 = (((const double *)A)[2 * (lda * j + (U + i - j)) + 1]);

            (((double *)Y)[2 * (iy)]) += A_real1 * tmpR - A_imag1 * tmpI;
            (((double *)Y)[2 * (iy) + 1]) += A_real1 * tmpI + A_imag1 * tmpR;

            if (i + 1 < i_max) {
                int iy_next = iy + stride;
                const double A_real2 = (((const double *)A)[2 * (lda * j + (U + (i + 1) - j))]);
                const double A_imag2 = (((const double *)A)[2 * (lda * j + (U + (i + 1) - j)) + 1]);

                (((double *)Y)[2 * (iy_next)]) += A_real2 * tmpR - A_imag2 * tmpI;
                (((double *)Y)[2 * (iy_next) + 1]) += A_real2 * tmpI + A_imag2 * tmpR;
            }
        }
    }
    ix += incX;
}
}
