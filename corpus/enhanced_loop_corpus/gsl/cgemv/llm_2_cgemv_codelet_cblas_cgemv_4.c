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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Modify access to A and Y to use consecutive strides by precomputing base pointers and using linear indexing.
    // This improves cache locality by accessing memory in a more predictable, sequential manner.

    float *Y_ptr = (float *)Y;
    const float *X_ptr = (const float *)X;
    const float *A_ptr = (const float *)A;

    for (j = 0; j < lenX; j++) {
        int x_index = 2 * ix;
        float x_real = X_ptr[x_index];
        float x_imag = X_ptr[x_index + 1];
        float tmpR = alpha_real * x_real - alpha_imag * x_imag;
        float tmpI = alpha_real * x_imag + alpha_imag * x_real;

        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        float *Y_base = &Y_ptr[2 * iy];

        for (i = 0; i < lenY; i++) {
            int a_index = 2 * (lda * j + i);
            const float A_real = A_ptr[a_index];
            const float A_imag = A_ptr[a_index + 1];

            Y_base[0] += A_real * tmpR + A_imag * tmpI;  // Note: -(-A_imag) => +A_imag
            Y_base[1] += A_real * tmpI - A_imag * tmpR;  // Sign corrected accordingly

            Y_base += 2 * incY;  // Stride in Y is now applied directly to pointer offset
        }
        ix += incX;
    }
}
