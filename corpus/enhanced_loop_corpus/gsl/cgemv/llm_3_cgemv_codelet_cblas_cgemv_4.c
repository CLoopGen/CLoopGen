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
    // Variant 2: Strided Memory Access with Reverse Traversal
    // Traverse the inner loop in reverse order with strided access to simulate non-unit stride patterns.
    // This variant uses negative strides and reverses loop bounds to demonstrate robustness.

    const float *X_ptr = (const float *)X;
    const float *A_ptr = (const float *)A;
    float *Y_ptr = (float *)Y;

    for (j = 0; j < lenX; j++) {
        int x_idx = 2 * ix;
        float x_real = X_ptr[x_idx];
        float x_imag = X_ptr[x_idx + 1];
        float tmpR = alpha_real * x_real - alpha_imag * x_imag;
        float tmpI = alpha_real * x_imag + alpha_imag * x_real;

        // Compute starting index for Y based on incY sign, but now traverse from end to start
        int start_iy = ((incY) > 0 ? (lenY - 1) * incY : 0);
        int step = ((incY) > 0 ? -incY : incY);  // Always subtract magnitude per iteration

        // Reverse inner loop: go from lenY-1 down to 0
        for (i = lenY - 1; i >= 0; i--) {
            int a_offset = 2 * (lda * j + i);
            const float A_real = A_ptr[a_offset];
            const float A_imag = A_ptr[a_offset + 1];

            int y_offset = 2 * (start_iy + i * step);  // Apply reversed strided offset
            Y_ptr[y_offset]     += A_real * tmpR + A_imag * tmpI;
            Y_ptr[y_offset + 1] += A_real * tmpI - A_imag * tmpR;
        }
        ix += incX;
    }
}
