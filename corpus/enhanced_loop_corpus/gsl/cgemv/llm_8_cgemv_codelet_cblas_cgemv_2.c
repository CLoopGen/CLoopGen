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
extern  float alpha_real;
extern  float alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *y_ptr_base = (float *)Y;
int iy_local = iy;
for (i = 0; i < lenY; i++) {
    float dotR = 0.0f;
    float dotI = 0.0f;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        int a_index = 2 * (lda * i + j);
        int x_index = 2 * ix;
        const float x_real = ((const float *)X)[x_index];
        const float x_imag = ((const float *)X)[x_index + 1];
        const float A_real = ((const float *)A)[a_index];
        const float A_imag = ((const float *)A)[a_index + 1];
        float productR = A_real * x_real - A_imag * x_imag;
        float productI = A_real * x_imag + A_imag * x_real;
        dotR = dotR + productR;
        dotI = dotI + productI;
        ix += incX;
    }
    int y_index = 2 * iy_local;
    float Y_temp_real = y_ptr_base[y_index];
    float Y_temp_imag = y_ptr_base[y_index + 1];
    float alpha_dotR = alpha_real * dotR;
    float alpha_dotI = alpha_real * dotI;
    float beta_dotR = alpha_imag * dotI;
    float beta_dotI = alpha_imag * dotR;
    Y_temp_real += alpha_dotR - beta_dotR;
    Y_temp_imag += alpha_dotI + beta_dotI;
    y_ptr_base[y_index] = Y_temp_real;
    y_ptr_base[y_index + 1] = Y_temp_imag;
    iy_local += incY;
}
iy = iy_local;
}
