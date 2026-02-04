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
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N && N > 0; i++) {
    float temp_real_diag = 0.;
    int k_unroll = K / 4 * 4;
    for (k = 0; k < k_unroll; k += 4) {
        const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
        const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
        const float Aik2_real = (((const float *)A)[2 * (i * lda + k + 2)]);
        const float Aik2_imag = (((const float *)A)[2 * (i * lda + k + 2) + 1]);
        const float Aik3_real = (((const float *)A)[2 * (i * lda + k + 3)]);
        const float Aik3_imag = (((const float *)A)[2 * (i * lda + k + 3) + 1]);

        const float temp1_real_0 = alpha_real * Aik0_real - alpha_imag * Aik0_imag;
        const float temp1_imag_0 = alpha_real * Aik0_imag + alpha_imag * Aik0_real;
        const float temp1_real_1 = alpha_real * Aik1_real - alpha_imag * Aik1_imag;
        const float temp1_imag_1 = alpha_real * Aik1_imag + alpha_imag * Aik1_real;
        const float temp1_real_2 = alpha_real * Aik2_real - alpha_imag * Aik2_imag;
        const float temp1_imag_2 = alpha_real * Aik2_imag + alpha_imag * Aik2_real;
        const float temp1_real_3 = alpha_real * Aik3_real - alpha_imag * Aik3_imag;
        const float temp1_imag_3 = alpha_real * Aik3_imag + alpha_imag * Aik3_real;

        const float Bik0_real = (((const float *)B)[2 * (i * ldb + k)]);
        const float Bik0_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
        const float Bik1_real = (((const float *)B)[2 * (i * ldb + k + 1)]);
        const float Bik1_imag = (((const float *)B)[2 * (i * ldb + k + 1) + 1]);
        const float Bik2_real = (((const float *)B)[2 * (i * ldb + k + 2)]);
        const float Bik2_imag = (((const float *)B)[2 * (i * ldb + k + 2) + 1]);
        const float Bik3_real = (((const float *)B)[2 * (i * ldb + k + 3)]);
        const float Bik3_imag = (((const float *)B)[2 * (i * ldb + k + 3) + 1]);

        temp_real_diag += temp1_real_0 * Bik0_real + temp1_imag_0 * Bik0_imag +
                          temp1_real_1 * Bik1_real + temp1_imag_1 * Bik1_imag +
                          temp1_real_2 * Bik2_real + temp1_imag_2 * Bik2_imag +
                          temp1_real_3 * Bik3_real + temp1_imag_3 * Bik3_imag;
    }
    for (; k < K; k++) {
        const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
        const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
        const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
        const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
        temp_real_diag += temp1_real * Bik_real + temp1_imag * Bik_imag;
    }
    (((float *)C)[2 * (i * ldc + i)]) += 2 * temp_real_diag;
    (((float *)C)[2 * (i * ldc + i) + 1]) = 0.;

    for (j = i + 1; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k += 2) {
            if (k + 1 < K) {
                const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
                const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
                const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
                const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);

                const float temp1_real_0 = alpha_real * Aik0_real - alpha_imag * Aik0_imag;
                const float temp1_imag_0 = alpha_real * Aik0_imag + alpha_imag * Aik0_real;
                const float temp1_real_1 = alpha_real * Aik1_real - alpha_imag * Aik1_imag;
                const float temp1_imag_1 = alpha_real * Aik1_imag + alpha_imag * Aik1_real;

                const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
                const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
                const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
                const float Ajk1_imag = (((const float *)A)[2 * (j * lda + k + 1) + 1]);

                const float temp2_real_0 = alpha_real * Ajk0_real - alpha_imag * Ajk0_imag;
                const float temp2_imag_0 = alpha_real * Ajk0_imag + alpha_imag * Ajk0_real;
                const float temp2_real_1 = alpha_real * Ajk1_real - alpha_imag * Ajk1_imag;
                const float temp2_imag_1 = alpha_real * Ajk1_imag + alpha_imag * Ajk1_real;

                const float Bjk0_real = (((const float *)B)[2 * (j * ldb + k)]);
                const float Bjk0_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);
                const float Bjk1_real = (((const float *)B)[2 * (j * ldb + k + 1)]);
                const float Bjk1_imag = (((const float *)B)[2 * (j * ldb + k + 1) + 1]);

                const float Bik0_real = (((const float *)B)[2 * (i * ldb + k)]);
                const float Bik0_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
                const float Bik1_real = (((const float *)B)[2 * (i * ldb + k + 1)]);
                const float Bik1_imag = (((const float *)B)[2 * (i * ldb + k + 1) + 1]);

                temp_real += (temp1_real_0 * Bjk0_real + temp1_imag_0 * Bjk0_imag +
                              temp1_real_1 * Bjk1_real + temp1_imag_1 * Bjk1_imag) +
                             (Bik0_real * temp2_real_0 + Bik0_imag * temp2_imag_0 +
                              Bik1_real * temp2_real_1 + Bik1_imag * temp2_imag_1);

                temp_imag += (temp1_real_0 * (-Bjk0_imag) + temp1_imag_0 * Bjk0_real +
                              temp1_real_1 * (-Bjk1_imag) + temp1_imag_1 * Bjk1_real) +
                             (Bik0_real * (-temp2_imag_0) + Bik0_imag * temp2_real_0 +
                              Bik1_real * (-temp2_imag_1) + Bik1_imag * temp2_real_1);
            } else {
                const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
                const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
                const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
                const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;

                const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
                const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
                const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
                const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

                const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
                const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);
                const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
                const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);

                temp_real += temp1_real * Bjk_real + temp1_imag * Bjk_imag +
                             Bik_real * temp2_real + Bik_imag * temp2_imag;
                temp_imag += temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real +
                             Bik_real * (-temp2_imag) + Bik_imag * temp2_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp_imag;
    }
}
}
