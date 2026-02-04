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
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const int Aik_idx = 2 * (i * lda + k);
            const int Bik_idx = 2 * (i * ldb + k);
            const int Ajk_idx = 2 * (j * lda + k);
            const int Bjk_idx = 2 * (j * ldb + k);
            const double Aik_real = ((const double *)A)[Aik_idx];
            const double Aik_imag = ((const double *)A)[Aik_idx + 1];
            const double Bik_real = ((const double *)B)[Bik_idx];
            const double Bik_imag = ((const double *)B)[Bik_idx + 1];
            const double Ajk_real = ((const double *)A)[Ajk_idx];
            const double Ajk_imag = ((const double *)A)[Ajk_idx + 1];
            const double Bjk_real = ((const double *)B)[Bjk_idx];
            const double Bjk_imag = ((const double *)B)[Bjk_idx + 1];
            temp_real += ((Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag));
            temp_imag += ((Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real));
        }
        const int Cij_idx = 2 * (i * ldc + j);
        ((double *)C)[Cij_idx]     += alpha_real * temp_real - alpha_imag * temp_imag;
        ((double *)C)[Cij_idx + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
