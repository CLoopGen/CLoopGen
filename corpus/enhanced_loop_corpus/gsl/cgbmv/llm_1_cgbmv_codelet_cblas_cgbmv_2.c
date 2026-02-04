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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    float dotR = 0.;
    float dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (int k = j_min; k < j_max; k++) {
        const float x_real = (((const float *)X)[2 * (ix)]);
        const float x_imag = (((const float *)X)[2 * (ix) + 1]);
        const float A_real = (((const float *)A)[2 * (lda * i + (L + k - i))]);
        const float A_imag = (((const float *)A)[2 * (lda * i + (L + k - i)) + 1]);
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
        ix += incX;
        if ((k + 1) % 4 == 0 || k == j_max - 1) {
            float tempR = dotR, tempI = dotI;
            dotR = 0.; dotI = 0.;
            (((float *)Y)[2 * (iy)]) += alpha_real * tempR - alpha_imag * tempI;
            (((float *)Y)[2 * (iy) + 1]) += alpha_real * tempI + alpha_imag * tempR;
            iy += incY;
            if (k < j_max - 1) {
                i++;
                if (i >= lenY) break;
                const int new_j_min = (i > L ? i - L : 0);
                const int new_j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
                ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + new_j_min * incX;
                j = new_j_min;
                for (; j < new_j_max && j <= k + 1; j++) {
                    const float x_real_inner = (((const float *)X)[2 * (ix)]);
                    const float x_imag_inner = (((const float *)X)[2 * (ix) + 1]);
                    const float A_real_inner = (((const float *)A)[2 * (lda * i + (L + j - i))]);
                    const float A_imag_inner = (((const float *)A)[2 * (lda * i + (L + j - i)) + 1]);
                    dotR += A_real_inner * x_real_inner - A_imag_inner * x_imag_inner;
                    dotI += A_real_inner * x_imag_inner + A_imag_inner * x_real_inner;
                    ix += incX;
                }
            }
            break;
        }
    }
}
}
