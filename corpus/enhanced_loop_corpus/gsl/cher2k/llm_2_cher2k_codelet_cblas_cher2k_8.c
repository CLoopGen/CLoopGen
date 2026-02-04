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
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modify memory access pattern to use consecutive loading with pointer arithmetic
    // Instead of recalculating array indices repeatedly, use base pointers and increment them
    for (k = 0; k < K; k++) {
        const float *A_k = (const float *)(A) + 2 * k * lda;
        const float *B_k = (const float *)(B) + 2 * k * ldb;
        float *C_i_row;
        for (i = 0; i < N; i++) {
            const float *A_ki = A_k + 2 * i;
            const float *B_ki = B_k + 2 * i;
            float Aki_real = A_ki[0];
            float Aki_imag = A_ki[1];
            float Bki_real = B_ki[0];
            float Bki_imag = B_ki[1];
            float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

            C_i_row = (float *)C + 2 * (i * lda);
            for (j = 0; j < i; j++) {
                const float *A_kj = A_k + 2 * j;
                const float *B_kj = B_k + 2 * j;
                float Akj_real = A_kj[0];
                float Akj_imag = A_kj[1];
                float Bkj_real = B_kj[0];
                float Bkj_imag = B_kj[1];
                float *C_ij = C_i_row + 2 * j;
                C_ij[0] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                           (temp2_real * Akj_real - temp2_imag * Akj_imag);
                C_ij[1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                           (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            float *C_ii = C_i_row + 2 * i;
            C_ii[0] += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            C_ii[1] = 0.0f;
        }
    }
}
