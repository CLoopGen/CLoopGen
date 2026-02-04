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
        for (k = 0; k < K; k++) {
            const int idxA = 2 * (i * lda + k);
            const int idxB = 2 * (i * ldb + k);
            const double Aik_real = ((const double *)A)[idxA];
            const double Aik_imag = ((const double *)A)[idxA + 1];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = ((const double *)B)[idxB];
            const double Bik_imag = ((const double *)B)[idxB + 1];
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        const int Ci_diag = 2 * (i * ldc + i);
        ((double *)C)[Ci_diag] += 2 * temp_real;
        ((double *)C)[Ci_diag + 1] = 0.;
    }
    for (j = i + 1; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const int idxAi = 2 * (i * lda + k);
            const int idxAj = 2 * (j * lda + k);
            const int idxBi = 2 * (i * ldb + k);
            const int idxBj = 2 * (j * ldb + k);
            const double Aik_real = ((const double *)A)[idxAi];
            const double Aik_imag = ((const double *)A)[idxAi + 1];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = ((const double *)B)[idxBi];
            const double Bik_imag = ((const double *)B)[idxBi + 1];
            const double Ajk_real = ((const double *)A)[idxAj];
            const double Ajk_imag = ((const double *)A)[idxAj + 1];
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const double Bjk_real = ((const double *)B)[idxBj];
            const double Bjk_imag = ((const double *)B)[idxBj + 1];
            temp_real += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));
        }
        const int C_idx = 2 * (i * ldc + j);
        ((double *)C)[C_idx] += temp_real;
        ((double *)C)[C_idx + 1] += temp_imag;
    }
}
}
