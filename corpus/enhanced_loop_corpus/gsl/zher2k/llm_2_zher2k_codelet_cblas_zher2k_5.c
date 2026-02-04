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
extern  double alpha_real;
extern double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    {
        double temp_real = 0.;
        const double *Ai_real = &(((const double *)A)[2 * i * lda]);
        const double *Ai_imag = &(((const double *)A)[2 * i * lda + 1]);
        const double *Bi_real = &(((const double *)B)[2 * i * ldb]);
        const double *Bi_imag = &(((const double *)B)[2 * i * ldb + 1]);
        for (k = 0; k < K; k++) {
            const double Aik_real = Ai_real[2 * k];
            const double Aik_imag = Ai_imag[2 * k];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = Bi_real[2 * k];
            const double Bik_imag = Bi_imag[2 * k];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((double *)C)[2 * (i * ldc + i)]) += 2 * temp_real;
        (((double *)C)[2 * (i * ldc + i) + 1]) = 0.;
    }
    for (j = i + 1; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *Ai_real = &(((const double *)A)[2 * i * lda]);
        const double *Ai_imag = &(((const double *)A)[2 * i * lda + 1]);
        const double *Aj_real = &(((const double *)A)[2 * j * lda]);
        const double *Aj_imag = &(((const double *)A)[2 * j * lda + 1]);
        const double *Bi_real = &(((const double *)B)[2 * i * ldb]);
        const double *Bi_imag = &(((const double *)B)[2 * i * ldb + 1]);
        const double *Bj_real = &(((const double *)B)[2 * j * ldb]);
        const double *Bj_imag = &(((const double *)B)[2 * j * ldb + 1]);
        for (k = 0; k < K; k++) {
            const double Aik_real = Ai_real[2 * k];
            const double Aik_imag = Ai_imag[2 * k];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = Bi_real[2 * k];
            const double Bik_imag = Bi_imag[2 * k];
            const double Ajk_real = Aj_real[2 * k];
            const double Ajk_imag = Aj_imag[2 * k];
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const double Bjk_real = Bj_real[2 * k];
            const double Bjk_imag = Bj_imag[2 * k];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        (((double *)C)[2 * (i * ldc + j)]) += temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp_imag;
    }
}
}
