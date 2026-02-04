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
    const int Ci_ldc = i * ldc;
    const int Ai_lda = i * lda;
    const int Bi_ldb = i * ldb;
    for (j = 0; j < i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const int Cij_offset = Ci_ldc + j;
        const int Aj_lda = j * lda;
        const int Bj_ldb = j * ldb;
        for (k = 0; k < K; k++) {
            const int A_ik_idx = 2 * (Ai_lda + k);
            const int B_jk_idx = 2 * (Bj_ldb + k);
            const int A_jk_idx = 2 * (Aj_lda + k);
            const int B_ik_idx = 2 * (Bi_ldb + k);

            const double Aik_real = ((const double*)A)[A_ik_idx];
            const double Aik_imag = ((const double*)A)[A_ik_idx + 1];
            const double Bjk_real = ((const double*)B)[B_jk_idx];
            const double Bjk_imag = ((const double*)B)[B_jk_idx + 1];
            const double Ajk_real = ((const double*)A)[A_jk_idx];
            const double Ajk_imag = ((const double*)A)[A_jk_idx + 1];
            const double Bik_real = ((const double*)B)[B_ik_idx];
            const double Bik_imag = ((const double*)B)[B_ik_idx + 1];

            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

            temp_real += (temp1_real * Bjk_real + temp1_imag * Bjk_imag) +
                         (Bik_real * temp2_real + Bik_imag * temp2_imag);
            temp_imag += (temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) +
                         (Bik_real * (-temp2_imag) + Bik_imag * temp2_real);
        }
        ((double*)C)[2 * Cij_offset] += temp_real;
        ((double*)C)[2 * Cij_offset + 1] += temp_imag;
    }
    {
        double temp_real = 0.;
        const int Cii_offset = 2 * (Ci_ldc + i);
        for (k = 0; k < K; k++) {
            const int Aik_idx = 2 * (Ai_lda + k);
            const int Bik_idx = 2 * (Bi_ldb + k);
            const double Aik_real = ((const double*)A)[Aik_idx];
            const double Aik_imag = ((const double*)A)[Aik_idx + 1];
            const double Bik_real = ((const double*)B)[Bik_idx];
            const double Bik_imag = ((const double*)B)[Bik_idx + 1];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        ((double*)C)[Cii_offset] += 2 * temp_real;
        ((double*)C)[Cii_offset + 1] = 0.;
    }
}
}
