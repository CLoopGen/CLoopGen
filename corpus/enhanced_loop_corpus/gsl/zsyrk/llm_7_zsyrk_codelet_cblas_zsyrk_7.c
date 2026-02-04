#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Reverse loop order to eliminate certain loop-carried dependencies and change memory access pattern
// Now we traverse i and j in reverse, which removes forward loop-carried dependencies
// Still computes the same values but with different data traversal order
for (i = N - 1; i >= 0; i--) {
    for (j = i; j >= 0; j--) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Unroll inner loop by factor of 2 to introduce local reuse and modify RAW/WAR dependencies
        k = 0;
        for (; k < K - 1; k += 2) {
            const double Aki0_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki0_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj0_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj0_imag = (((const double *)A)[2 * (k * lda + j) + 1]);

            const double Aki1_real = (((const double *)A)[2 * ((k+1) * lda + i)]);
            const double Aki1_imag = (((const double *)A)[2 * ((k+1) * lda + i) + 1]);
            const double Akj1_real = (((const double *)A)[2 * ((k+1) * lda + j)]);
            const double Akj1_imag = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);

            temp_real += Aki0_real * Akj0_real - Aki0_imag * Akj0_imag;
            temp_imag += Aki0_real * Akj0_imag + Aki0_imag * Akj0_real;

            temp_real += Aki1_real * Akj1_real - Aki1_imag * Akj1_imag;
            temp_imag += Aki1_real * Akj1_imag + Aki1_imag * Akj1_real;
        }
        // Handle remaining element if K is odd
        if (k < K) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
