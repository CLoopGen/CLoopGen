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
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

            double term1_real = Aik_real * Bjk_real - Aik_imag * Bjk_imag;
            double term1_imag = Aik_real * Bjk_imag + Aik_imag * Bjk_real;
            double term2_real = Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            double term2_imag = Bik_real * Ajk_imag + Bik_imag * Ajk_real;

            temp_real += term1_real + term2_real;
            temp_imag += term1_imag + term2_imag;
        }

        double Cij_real = (((double *)C)[2 * (i * ldc + j)]);
        double Cij_imag = (((double *)C)[2 * (i * ldc + j) + 1]);

        Cij_real += alpha_real * temp_real - alpha_imag * temp_imag;
        Cij_imag += alpha_real * temp_imag + alpha_imag * temp_real;

        (((double *)C)[2 * (i * ldc + j)]) = Cij_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) = Cij_imag;
    }
}
}
