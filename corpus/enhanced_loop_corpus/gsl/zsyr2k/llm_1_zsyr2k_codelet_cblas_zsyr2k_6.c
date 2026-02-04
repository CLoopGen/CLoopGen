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
    for (k = 0; k < K; k++) {
        for (j = 0; j <= i; j++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);
            const double prod1_real = Aik_real * Bjk_real - Aik_imag * Bjk_imag;
            const double prod1_imag = Aik_real * Bjk_imag + Aik_imag * Bjk_real;
            const double prod2_real = Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            const double prod2_imag = Bik_real * Ajk_imag + Bik_imag * Ajk_real;
            (((double *)C)[2 * (i * ldc + j)]) += alpha_real * (prod1_real + prod2_real) - alpha_imag * (prod1_imag + prod2_imag);
            (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * (prod1_imag + prod2_imag) + alpha_imag * (prod1_real + prod2_real);
        }
    }
}
}
