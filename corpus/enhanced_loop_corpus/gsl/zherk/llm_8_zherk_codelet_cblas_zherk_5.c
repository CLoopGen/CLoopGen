#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        double temp_real_0 = 0.;
        double temp_imag_0 = 0.;
        double temp_real_1 = 0.;
        double temp_imag_1 = 0.;
        for (k = 0; k < K; k++) {
            const double Aik0_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik0_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Aik1_real = (((const double *)A)[2 * ((i+1) * lda + k)]);
            const double Aik1_imag = (((const double *)A)[2 * ((i+1) * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = -(((const double *)A)[2 * (j * lda + k) + 1]);

            temp_real_0 += Aik0_real * Ajk_real - Aik0_imag * Ajk_imag;
            temp_imag_0 += Aik0_real * Ajk_imag + Aik0_imag * Ajk_real;

            temp_real_1 += Aik1_real * Ajk_real - Aik1_imag * Ajk_imag;
            temp_imag_1 += Aik1_real * Ajk_imag + Aik1_imag * Ajk_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (i + 1 < N) {
            (((double *)C)[2 * ((i+1) * ldc + j)]) += alpha * temp_real_1;
            (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
