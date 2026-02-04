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
    for (j = 0; j <= i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *A_i = &((const double *)A)[2 * (i * lda)];
        const double *A_j = &((const double *)A)[2 * (j * lda)];
        for (k = 0; k < K; k++) {
            const double Aik_real = A_i[2 * k];
            const double Aik_imag = A_i[2 * k + 1];
            const double Ajk_real = A_j[2 * k];
            const double Ajk_imag = -A_j[2 * k + 1];
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        double *C_ij = &((double *)C)[2 * (i * ldc + j)];
        C_ij[0] += alpha * temp_real;
        C_ij[1] += alpha * temp_imag;
    }
}
}
