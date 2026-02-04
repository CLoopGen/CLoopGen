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
    // Variant 2: Strided Memory Access with Blocked Vector-Like Access Pattern
    const int block_size = 4; // Block size for strided access simulation
    for (k = 0; k < K; k += block_size) {
        for (i = 0; i < N; i++) {
            float Aki_real[4], Aki_imag[4];
            float Bki_real[4], Bki_imag[4];
            float temp1_real[4], temp1_imag[4];
            float temp2_real[4], temp2_imag[4];

            int actual_block = 0;
            for (int kb = 0; kb < block_size; kb++) {
                if (k + kb >= K) break;
                actual_block++;
                Aki_real[kb] = (((const float *)A)[2 * ((k + kb) * lda + i)]);
                Aki_imag[kb] = (((const float *)A)[2 * ((k + kb) * lda + i) + 1]);
                Bki_real[kb] = (((const float *)B)[2 * ((k + kb) * ldb + i)]);
                Bki_imag[kb] = (((const float *)B)[2 * ((k + kb) * ldb + i) + 1]);

                temp1_real[kb] = alpha_real * Aki_real[kb] - alpha_imag * Aki_imag[kb];
                temp1_imag[kb] = alpha_real * Aki_imag[kb] + alpha_imag * Aki_real[kb];
                temp2_real[kb] = alpha_real * Bki_real[kb] - alpha_imag * Bki_imag[kb];
                temp2_imag[kb] = alpha_real * Bki_imag[kb] + alpha_imag * Bki_real[kb];
            }

            for (j = i; j < N; j++) {
                float Cij_real = 0.0f, Cij_imag = 0.0f;
                for (int kb = 0; kb < actual_block; kb++) {
                    float Akj_real = (((const float *)A)[2 * ((k + kb) * lda + j)]);
                    float Akj_imag = (((const float *)A)[2 * ((k + kb) * lda + j) + 1]);
                    float Bkj_real = (((const float *)B)[2 * ((k + kb) * ldb + j)]);
                    float Bkj_imag = (((const float *)B)[2 * ((k + kb) * ldb + j) + 1]);

                    Cij_real += (temp1_real[kb] * Bkj_real - temp1_imag[kb] * Bkj_imag) +
                                (temp2_real[kb] * Akj_real - temp2_imag[kb] * Akj_imag);
                    Cij_imag += (temp1_real[kb] * Bkj_imag + temp1_imag[kb] * Bkj_real) +
                                (temp2_real[kb] * Akj_imag + temp2_imag[kb] * Akj_real);
                }
                (((float *)C)[2 * (i * lda + j)]) += Cij_real;
                (((float *)C)[2 * (i * lda + j) + 1]) += Cij_imag;
            }
        }
    }
}
