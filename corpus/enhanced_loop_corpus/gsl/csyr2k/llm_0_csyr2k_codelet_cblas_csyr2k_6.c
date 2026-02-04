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
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        k = 0;
        #pragma unroll 4
        for (; k + 3 < K; k += 4) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k + 0)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k + 0) + 1]);
            const float Bik0_real = (((const float *)B)[2 * (i * ldb + k + 0)]);
            const float Bik0_imag = (((const float *)B)[2 * (i * ldb + k + 0) + 1]);
            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k + 0)]);
            const float Ajk0_imag = (((const float *)A)[2 * (j * lda + k + 0) + 1]);
            const float Bjk0_real = (((const float *)B)[2 * (j * ldb + k + 0)]);
            const float Bjk0_imag = (((const float *)B)[2 * (j * ldb + k + 0) + 1]);

            const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
            const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
            const float Bik1_real = (((const float *)B)[2 * (i * ldb + k + 1)]);
            const float Bik1_imag = (((const float *)B)[2 * (i * ldb + k + 1) + 1]);
            const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
            const float Ajk1_imag = (((const float *)A)[2 * (j * lda + k + 1) + 1]);
            const float Bjk1_real = (((const float *)B)[2 * (j * ldb + k + 1)]);
            const float Bjk1_imag = (((const float *)B)[2 * (j * ldb + k + 1) + 1]);

            const float Aik2_real = (((const float *)A)[2 * (i * lda + k + 2)]);
            const float Aik2_imag = (((const float *)A)[2 * (i * lda + k + 2) + 1]);
            const float Bik2_real = (((const float *)B)[2 * (i * ldb + k + 2)]);
            const float Bik2_imag = (((const float *)B)[2 * (i * ldb + k + 2) + 1]);
            const float Ajk2_real = (((const float *)A)[2 * (j * lda + k + 2)]);
            const float Ajk2_imag = (((const float *)A)[2 * (j * lda + k + 2) + 1]);
            const float Bjk2_real = (((const float *)B)[2 * (j * ldb + k + 2)]);
            const float Bjk2_imag = (((const float *)B)[2 * (j * ldb + k + 2) + 1]);

            const float Aik3_real = (((const float *)A)[2 * (i * lda + k + 3)]);
            const float Aik3_imag = (((const float *)A)[2 * (i * lda + k + 3) + 1]);
            const float Bik3_real = (((const float *)B)[2 * (i * ldb + k + 3)]);
            const float Bik3_imag = (((const float *)B)[2 * (i * ldb + k + 3) + 1]);
            const float Ajk3_real = (((const float *)A)[2 * (j * lda + k + 3)]);
            const float Ajk3_imag = (((const float *)A)[2 * (j * lda + k + 3) + 1]);
            const float Bjk3_real = (((const float *)B)[2 * (j * ldb + k + 3)]);
            const float Bjk3_imag = (((const float *)B)[2 * (j * ldb + k + 3) + 1]);

            temp_real += (Aik0_real * Bjk0_real - Aik0_imag * Bjk0_imag) + (Bik0_real * Ajk0_real - Bik0_imag * Ajk0_imag);
            temp_imag += (Aik0_real * Bjk0_imag + Aik0_imag * Bjk0_real) + (Bik0_real * Ajk0_imag + Bik0_imag * Ajk0_real);

            temp_real += (Aik1_real * Bjk1_real - Aik1_imag * Bjk1_imag) + (Bik1_real * Ajk1_real - Bik1_imag * Ajk1_imag);
            temp_imag += (Aik1_real * Bjk1_imag + Aik1_imag * Bjk1_real) + (Bik1_real * Ajk1_imag + Bik1_imag * Ajk1_real);

            temp_real += (Aik2_real * Bjk2_real - Aik2_imag * Bjk2_imag) + (Bik2_real * Ajk2_real - Bik2_imag * Ajk2_imag);
            temp_imag += (Aik2_real * Bjk2_imag + Aik2_imag * Bjk2_real) + (Bik2_real * Ajk2_imag + Bik2_imag * Ajk2_real);

            temp_real += (Aik3_real * Bjk3_real - Aik3_imag * Bjk3_imag) + (Bik3_real * Ajk3_real - Bik3_imag * Ajk3_imag);
            temp_imag += (Aik3_real * Bjk3_imag + Aik3_imag * Bjk3_real) + (Bik3_real * Ajk3_imag + Bik3_imag * Ajk3_real);
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
            temp_real += ((Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag));
            temp_imag += ((Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real));
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
