#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational complexity by eliminating redundant memory accesses and fusing computations
// Use a single loop over k and collapse i and j into one loop with conditional logic to maintain correctness

for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
        float temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        float temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;

        // Compute only diagonal and lower triangle, but avoid repeated loads of Akj/Bkj
        // Reuse values from A and B in register where possible, minimize address recalculation
        for (j = 0; j <= i; j += 2) { // Process two j elements per iteration
            // First j element
            float Akj_real_0 = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag_0 = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real_0 = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag_0 = (((const float *)B)[2 * (k * ldb + j) + 1]);

            float Cij_real_0 = (temp1_real * Bkj_real_0 - temp1_imag * Bkj_imag_0) +
                              (temp2_real * Akj_real_0 - temp2_imag * Akj_imag_0);
            float Cij_imag_0 = (temp1_real * Bkj_imag_0 + temp1_imag * Bkj_real_0) +
                              (temp2_real * Akj_imag_0 + temp2_imag * Akj_real_0);

            (((float *)C)[2 * (i * lda + j)]) += Cij_real_0;
            (((float *)C)[2 * (i * lda + j) + 1]) += Cij_imag_0;

            // Second j element, if valid
            if (j + 1 <= i) {
                float Akj_real_1 = (((const float *)A)[2 * (k * lda + j + 1)]);
                float Akj_imag_1 = (((const float *)A)[2 * (k * lda + j + 1) + 1]);
                float Bkj_real_1 = (((const float *)B)[2 * (k * ldb + j + 1)]);
                float Bkj_imag_1 = (((const float *)B)[2 * (k * ldb + j + 1) + 1]);

                float Cij_real_1 = (temp1_real * Bkj_real_1 - temp1_imag * Bkj_imag_1) +
                                  (temp2_real * Akj_real_1 - temp2_imag * Akj_imag_1);
                float Cij_imag_1 = (temp1_real * Bkj_imag_1 + temp1_imag * Bkj_real_1) +
                                  (temp2_real * Akj_imag_1 + temp2_imag * Akj_real_1);

                (((float *)C)[2 * (i * lda + j + 1)]) += Cij_real_1;
                (((float *)C)[2 * (i * lda + j + 1) + 1]) += Cij_imag_1;
            }
        }
    }
}
}
