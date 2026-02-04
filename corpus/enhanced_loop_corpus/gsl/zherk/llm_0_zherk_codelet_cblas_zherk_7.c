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
    double temp_real_inner;
    double temp_imag_inner;
    for (j = 0; j <= i; j++) {
        temp_real_inner = 0.;
        temp_imag_inner = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = -(((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real_inner += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag_inner += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real_inner;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_inner;
    }
}
}
