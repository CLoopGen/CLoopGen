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
for (i = 0; i < N; i++) {
    for (j = i; j < N; j += 2) {
        double temp_real_0 = 0.;
        double temp_imag_0 = 0.;
        double temp_real_1 = 0.;
        double temp_imag_1 = 0.;
        const int compute_j1 = (j + 1 < N);
        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);

            const double Ajk0_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk0_imag = -(((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real_0 += Aik_real * Ajk0_real - Aik_imag * Ajk0_imag;
            temp_imag_0 += Aik_real * Ajk0_imag + Aik_imag * Ajk0_real;

            if (compute_j1) {
                const double Ajk1_real = (((const double *)A)[2 * ((j+1) * lda + k)]);
                const double Ajk1_imag = -(((const double *)A)[2 * ((j+1) * lda + k) + 1]);
                temp_real_1 += Aik_real * Ajk1_real - Aik_imag * Ajk1_imag;
                temp_imag_1 += Aik_real * Ajk1_imag + Aik_imag * Ajk1_real;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_0;
        if (compute_j1) {
            (((double *)C)[2 * (i * ldc + j + 1)]) += alpha * temp_real_1;
            (((double *)C)[2 * (i * ldc + j + 1) + 1]) += alpha * temp_imag_1;
        }
    }
}
}
