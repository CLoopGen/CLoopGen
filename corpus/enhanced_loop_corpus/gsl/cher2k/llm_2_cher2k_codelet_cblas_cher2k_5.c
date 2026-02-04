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
for (i = 0; i < N; i++) {
    {
        float temp_real = 0.;
        const float *Ai_real = &(((const float *)A)[2 * (i * lda)]);
        const float *Ai_imag = &(((const float *)A)[2 * (i * lda) + 1]);
        const float *Bi_real = &(((const float *)B)[2 * (i * ldb)]);
        const float *Bi_imag = &(((const float *)B)[2 * (i * ldb) + 1]);
        for (k = 0; k < K; k++) {
            const float Aik_real = Ai_real[2 * k];
            const float Aik_imag = Ai_imag[2 * k];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = Bi_real[2 * k];
            const float Bik_imag = Bi_imag[2 * k];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((float *)C)[2 * (i * ldc + i)]) += 2 * temp_real;
        (((float *)C)[2 * (i * ldc + i) + 1]) = 0.;
    }
    for (j = i + 1; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *Ai_real = &(((const float *)A)[2 * (i * lda)]);
        const float *Ai_imag = &(((const float *)A)[2 * (i * lda) + 1]);
        const float *Aj_real = &(((const float *)A)[2 * (j * lda)]);
        const float *Aj_imag = &(((const float *)A)[2 * (j * lda) + 1]);
        const float *Bi_real = &(((const float *)B)[2 * (i * ldb)]);
        const float *Bi_imag = &(((const float *)B)[2 * (i * ldb) + 1]);
        const float *Bj_real = &(((const float *)B)[2 * (j * ldb)]);
        const float *Bj_imag = &(((const float *)B)[2 * (j * ldb) + 1]);
        for (k = 0; k < K; k++) {
            const float Aik_real = Ai_real[2 * k];
            const float Aik_imag = Ai_imag[2 * k];
            const float temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const float temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const float Bik_real = Bi_real[2 * k];
            const float Bik_imag = Bi_imag[2 * k];
            const float Ajk_real = Aj_real[2 * k];
            const float Ajk_imag = Aj_imag[2 * k];
            const float temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const float temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const float Bjk_real = Bj_real[2 * k];
            const float Bjk_imag = Bj_imag[2 * k];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        (((float *)C)[2 * (i * ldc + j)]) += temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp_imag;
    }
}
}
