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
// Reverse outer loop iteration order to eliminate original loop-carried dependency direction
// This creates a backward loop-carried dependency (WAW on Y via decreasing iy)
int i_rev;
for (i_rev = lenY - 1; i_rev >= 0; i_rev--) {
    i = i_rev;
    float dotR = 0.0f;
    float dotI = 0.0f;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    // Use a separate index variable to decouple address calculation from loop induction
    int offset_base = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    int ix = offset_base + j_min * incX;
    // Unroll inner loop by factor of 2 to introduce partial redundancy and modify RAW dependencies
    j = j_min;
    // Handle unaligned start if needed (simplified: assume no remainder handling required)
    for (; j + 1 < j_max; j += 2) {
        // First element
        const float x_real1 = (((const float *)X)[2 * ix]);
        const float x_imag1 = (((const float *)X)[2 * ix + 1]);
        const float A_real1 = (((const float *)A)[2 * (lda * i + (L + j - i))]);
        const float A_imag1 = (((const float *)A)[2 * (lda * i + (L + j - i)) + 1]);
        dotR += A_real1 * x_real1 - A_imag1 * x_imag1;
        dotI += A_real1 * x_imag1 + A_imag1 * x_real1;
        ix += incX;

        // Second element
        const float x_real2 = (((const float *)X)[2 * ix]);
        const float x_imag2 = (((const float *)X)[2 * ix + 1]);
        const float A_real2 = (((const float *)A)[2 * (lda * i + (L + j + 1 - i))]);
        const float A_imag2 = (((const float *)A)[2 * (lda * i + (L + j + 1 - i)) + 1]);
        dotR += A_real2 * x_real2 - A_imag2 * x_imag2;
        dotI += A_real2 * x_imag2 + A_imag2 * x_real2;
        ix += incX;
    }
    // Handle remaining element if any
    for (; j < j_max; j++) {
        const float x_real = (((const float *)X)[2 * ix]);
        const float x_imag = (((const float *)X)[2 * ix + 1]);
        const float A_real = (((const float *)A)[2 * (lda * i + (L + j - i))]);
        const float A_imag = (((const float *)A)[2 * (lda * i + (L + j - i)) + 1]);
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
        ix += incX;
    }
    // Update Y using pre-decremented iy to establish reverse-order write
    iy -= incY; // Adjust iy before use due to reverse traversal
    (((float *)Y)[2 * iy]) += alpha_real * dotR - alpha_imag * dotI;
    (((float *)Y)[2 * iy + 1]) += alpha_real * dotI + alpha_imag * dotR;
}
}
