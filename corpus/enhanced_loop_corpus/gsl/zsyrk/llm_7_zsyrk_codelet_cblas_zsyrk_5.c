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
// Variant with reordered operations and modified loop-carried dependency via split accumulators
// Eliminates potential RAW hazard on temp by using two alternating accumulators per iteration
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        double temp_real_0 = 0., temp_real_1 = 0.;
        double temp_imag_0 = 0., temp_imag_1 = 0.;
        int k = 0;
        // Unroll by 2 to create independent computation streams and reduce loop-carried dependency chain length
        for (; k + 1 < K; k += 2) {
            // First k iteration
            const double Aki0_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki0_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj0_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj0_imag = (((const double *)A)[2 * (k * lda + j) + 1]);

            temp_real_0 += Aki0_real * Akj0_real - Aki0_imag * Akj0_imag;
            temp_imag_0 += Aki0_real * Akj0_imag + Aki0_imag * Akj0_real;

            // Second k+1 iteration – operates on independent data, breaks RAW dependency between consecutive k steps
            const double Aki1_real = (((const double *)A)[2 * ((k+1) * lda + i)]);
            const double Aki1_imag = (((const double *)A)[2 * ((k+1) * lda + i) + 1]);
            const double Akj1_real = (((const double *)A)[2 * ((k+1) * lda + j)]);
            const double Akj1_imag = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);

            temp_real_1 += Aki1_real * Akj1_real - Aki1_imag * Akj1_imag;
            temp_imag_1 += Aki1_real * Akj1_imag + Aki1_imag * Akj1_real;
        }
        // Combine accumulators
        double temp_real = temp_real_0 + temp_real_1;
        double temp_imag = temp_imag_0 + temp_imag_1;

        // Handle leftover iteration if K is odd
        for (; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }

        // Final update to C with combined result
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
