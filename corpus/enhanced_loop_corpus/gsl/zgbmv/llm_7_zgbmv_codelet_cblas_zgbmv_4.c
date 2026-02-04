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
double temp_accum_R[64] = {0};
double temp_accum_I[64] = {0};
int valid[64] = {0};
int batch_count = 0;
for (j = 0; j < lenX; j++) {
    const double x_real = (((const double *)X)[2 * (ix)]);
    const double x_imag = (((const double *)X)[2 * (ix) + 1]);
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    if (!(tmpR == 0. && tmpI == 0.)) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        for (i = i_min; i < i_max && batch_count < 64; i++) {
            const double A_real = (((const double *)A)[2 * (lda * j + (U + i - j))]);
            const double A_imag = (((const double *)A)[2 * (lda * j + (U + i - j)) + 1]);
            temp_accum_R[batch_count] += A_real * tmpR - (-A_imag) * tmpI;
            temp_accum_I[batch_count] += A_real * tmpI + (-A_imag) * tmpR;
            valid[batch_count] = iy;
            batch_count++;
            iy += incY;
        }
    }
    ix += incX;
}
for (int k = 0; k < batch_count; k++) {
    int y_idx = valid[k];
    (((double *)Y)[2 * y_idx]) += temp_accum_R[k];
    (((double *)Y)[2 * y_idx + 1]) += temp_accum_I[k];
}
}
