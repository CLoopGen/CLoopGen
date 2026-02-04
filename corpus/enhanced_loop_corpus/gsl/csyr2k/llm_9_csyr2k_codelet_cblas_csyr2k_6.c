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
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j += 2) {
        float temp_real1 = 0., temp_imag1 = 0.;
        float temp_real2 = 0., temp_imag2 = 0.;
        int k_unroll = K - (K % 4);
        for (k = 0; k < k_unroll; k += 4) {
            for (int r = 0; r < 4; r++) {
                const float Aik_real = (((const float *)A)[2 * (i * lda + k + r)]);
                const float Aik_imag = (((const float *)A)[2 * (i * lda + k + r) + 1]);
                const float Bik_real = (((const float *)B)[2 * (i * ldb + k + r)]);
                const float Bik_imag = (((const float *)B)[2 * (i * ldb + k + r) + 1]);
                const float Ajk_real = (((const float *)A)[2 * (j * lda + k + r)]);
                const float Ajk_imag = (((const float *)A)[2 * (j * lda + k + r) + 1]);
                const float Bjk_real = (((const float *)B)[2 * (j * ldb + k + r)]);
                const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k + r) + 1]);

                temp_real1 += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
                temp_imag1 += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);

                if (j + 1 <= i) {
                    const float Ajk2_real = (((const float *)A)[2 * ((j+1) * lda + k + r)]);
                    const float Ajk2_imag = (((const float *)A)[2 * ((j+1) * lda + k + r) + 1]);
                    const float Bjk2_real = (((const float *)B)[2 * ((j+1) * ldb + k + r)]);
                    const float Bjk2_imag = (((const float *)B)[2 * ((j+1) * ldb + k + r) + 1]);

                    temp_real2 += (Aik_real * Bjk2_real - Aik_imag * Bjk2_imag) + (Bik_real * Ajk2_real - Bik_imag * Ajk2_imag);
                    temp_imag2 += (Aik_real * Bjk2_imag + Aik_imag * Bjk2_real) + (Bik_real * Ajk2_imag + Bik_imag * Ajk2_real);
                }
            }
        }
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

            temp_real1 += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
            temp_imag1 += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);

            if (j + 1 <= i) {
                const float Ajk2_real = (((const float *)A)[2 * ((j+1) * lda + k)]);
                const float Ajk2_imag = (((const float *)A)[2 * ((j+1) * lda + k) + 1]);
                const float Bjk2_real = (((const float *)B)[2 * ((j+1) * ldb + k)]);
                const float Bjk2_imag = (((const float *)B)[2 * ((j+1) * ldb + k) + 1]);

                temp_real2 += (Aik_real * Bjk2_real - Aik_imag * Bjk2_imag) + (Bik_real * Ajk2_real - Bik_imag * Ajk2_imag);
                temp_imag2 += (Aik_real * Bjk2_imag + Aik_imag * Bjk2_real) + (Bik_real * Ajk2_imag + Bik_imag * Ajk2_real);
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;

        if (j + 1 <= i) {
            (((float *)C)[2 * (i * ldc + j + 1)]) += alpha_real * temp_real2 - alpha_imag * temp_imag2;
            (((float *)C)[2 * (i * ldc + j + 1) + 1]) += alpha_real * temp_imag2 + alpha_imag * temp_real2;
        }
    }
}
}
