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
extern  float alpha_real;
extern  float alpha_imag;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j++) {
    const int x_index = 2 * ix;
    const float x_real = ((const float*)X)[x_index];
    const float x_imag = ((const float*)X)[x_index + 1];
    float tmpR = alpha_real * x_real - alpha_imag * x_imag;
    float tmpI = alpha_real * x_imag + alpha_imag * x_real;
    if (!(tmpR == 0.0f && tmpI == 0.0f)) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = (lenY < j + L + 1 ? lenY : j + L + 1);
        int base_iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY));
        int iy_offset = base_iy + i_min * incY;
        float * restrict y_ptr = &((float*)Y)[iy_offset * 2];
        const float* restrict a_col_base = &((const float*)A)[2 * (lda * j + U - j)];
        for (i = i_min; i < i_max; i++) {
            const float A_real = a_col_base[2 * i];
            const float A_imag = a_col_base[2 * i + 1];
            y_ptr[0] += A_real * tmpR - A_imag * tmpI;
            y_ptr[1] += A_real * tmpI + A_imag * tmpR;
            y_ptr += 2 * incY;
        }
    }
    ix += incX;
}
}
