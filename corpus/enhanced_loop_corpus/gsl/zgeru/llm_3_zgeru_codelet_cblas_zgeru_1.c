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
extern  double alpha_real;
extern  double alpha_imag;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const double* restrict A_ptr = (const double*)A;
double* restrict A_mutable = (double*)A;
const double* restrict X_ptr = (const double*)X;
const double* restrict Y_ptr = (const double*)Y;

for (j = 0; j < N; j++) {
    const int y_offset = 2 * jy;
    const double Y_real = Y_ptr[y_offset];
    const double Y_imag = Y_ptr[y_offset + 1];
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        const int x_offset = 2 * ix;
        const double X_real = X_ptr[x_offset];
        const double X_imag = X_ptr[x_offset + 1];
        
        const int a_index = 2 * (i + lda * j);
        A_mutable[a_index] += X_real * tmp_real - X_imag * tmp_imag;
        A_mutable[a_index + 1] += X_imag * tmp_real + X_real * tmp_imag;
        
        ix += incX;
    }
    jy += incY;
}
}
