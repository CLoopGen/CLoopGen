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
    for (j = i; j < N; j += 2) {
        double temp_real0 = 0., temp_real1 = 0.;
        double temp_imag0 = 0., temp_imag1 = 0.;
        const int j1 = j + 1;
        const int valid_j1 = (j1 < N);

        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);

            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

            temp_real0 += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
            temp_imag0 += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);

            if (valid_j1) {
                const double Ajk1_real = (((const double *)A)[2 * (j1 * lda + k)]);
                const double Ajk1_imag = (((const double *)A)[2 * (j1 * lda + k) + 1]);
                const double Bjk1_real = (((const double *)B)[2 * (j1 * ldb + k)]);
                const double Bjk1_imag = (((const double *)B)[2 * (j1 * ldb + k) + 1]);

                temp_real1 += (Aik_real * Bjk1_real - Aik_imag * Bjk1_imag) + (Bik_real * Ajk1_real - Bik_imag * Ajk1_imag);
                temp_imag1 += (Aik_real * Bjk1_imag + Aik_imag * Bjk1_real) + (Bik_real * Ajk1_imag + Bik_imag * Ajk1_real);
            }
        }

        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real0 - alpha_imag * temp_imag0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag0 + alpha_imag * temp_real0;

        if (valid_j1) {
            (((double *)C)[2 * (i * ldc + j1)]) += alpha_real * temp_real1 - alpha_imag * temp_imag1;
            (((double *)C)[2 * (i * ldc + j1) + 1]) += alpha_real * temp_imag1 + alpha_imag * temp_real1;
        }
    }
}
}
