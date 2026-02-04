#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
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
    for (j = i; j < N && j < i + 4; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k += 2) {
            const double Aik0_real = (((const double *)A)[2 * (i * lda + k + 0)]);
            const double Aik0_imag = (((const double *)A)[2 * (i * lda + k + 0) + 1]);
            const double Ajk0_real = (((const double *)A)[2 * (j * lda + k + 0)]);
            const double Ajk0_imag = (((const double *)A)[2 * (j * lda + k + 0) + 1]);
            temp_real += Aik0_real * Ajk0_real - Aik0_imag * Ajk0_imag;
            temp_imag += Aik0_real * Ajk0_imag + Aik0_imag * Ajk0_real;

            if (k + 1 < K) {
                const double Aik1_real = (((const double *)A)[2 * (i * lda + k + 1)]);
                const double Aik1_imag = (((const double *)A)[2 * (i * lda + k + 1) + 1]);
                const double Ajk1_real = (((const double *)A)[2 * (j * lda + k + 1)]);
                const double Ajk1_imag = (((const double *)A)[2 * (j * lda + k + 1) + 1]);
                temp_real += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
                temp_imag += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
