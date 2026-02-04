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
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        double temp_real_0 = 0., temp_real_1 = 0.;
        double temp_imag_0 = 0., temp_imag_1 = 0.;
        for (k = 0; k < K; k++) {
            const double Aik0_real = (((const double *)A)[2 * ((i+0) * lda + k)]);
            const double Aik0_imag = (((const double *)A)[2 * ((i+0) * lda + k) + 1]);
            const double Bik0_real = (((const double *)B)[2 * ((i+0) * ldb + k)]);
            const double Bik0_imag = (((const double *)B)[2 * ((i+0) * ldb + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

            temp_real_0 += (Aik0_real * Bjk_real - Aik0_imag * Bjk_imag) + (Bik0_real * Ajk_real - Bik0_imag * Ajk_imag);
            temp_imag_0 += (Aik0_real * Bjk_imag + Aik0_imag * Bjk_real) + (Bik0_real * Ajk_imag + Bik0_imag * Ajk_real);

            if (i+1 < N) {
                const double Aik1_real = (((const double *)A)[2 * ((i+1) * lda + k)]);
                const double Aik1_imag = (((const double *)A)[2 * ((i+1) * lda + k) + 1]);
                const double Bik1_real = (((const double *)B)[2 * ((i+1) * ldb + k)]);
                const double Bik1_imag = (((const double *)B)[2 * ((i+1) * ldb + k) + 1]);

                temp_real_1 += (Aik1_real * Bjk_real - Aik1_imag * Bjk_imag) + (Bik1_real * Ajk_real - Bik1_imag * Ajk_imag);
                temp_imag_1 += (Aik1_real * Bjk_imag + Aik1_imag * Bjk_real) + (Bik1_real * Ajk_imag + Bik1_imag * Ajk_real);
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real_0 - alpha_imag * temp_imag_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag_0 + alpha_imag * temp_real_0;

        if (i+1 < N) {
            (((double *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp_real_1 - alpha_imag * temp_imag_1;
            (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp_imag_1 + alpha_imag * temp_real_1;
        }
    }
}
}
