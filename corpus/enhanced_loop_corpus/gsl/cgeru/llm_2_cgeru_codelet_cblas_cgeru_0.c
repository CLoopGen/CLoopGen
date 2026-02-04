#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern void *A;
extern  int lda;
extern int i;
extern int j;
extern  float alpha_real;
extern  float alpha_imag;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i++) {
    const float X_real = (((const float *)X)[2 * (ix)]);
    const float X_imag = (((const float *)X)[2 * (ix) + 1]);
    const float tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const float tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int jy = 0;
    for (j = 0; j < N; j++) {
        const int y_index = 2 * (jy);
        const float Y_real = (((const float *)Y)[y_index]);
        const float Y_imag = (((const float *)Y)[y_index + 1]);
        const int a_index = 2 * (lda * i + j);
        (((float *)A)[a_index]) += Y_real * tmp_real - Y_imag * tmp_imag;
        (((float *)A)[a_index + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
        jy += incY;
    }
    ix += incX;
}
}
