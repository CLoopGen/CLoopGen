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
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
        const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
        for (j = 0; j <= i; j++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double prod_real = Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            const double prod_imag = Aik_real * Ajk_imag + Aik_imag * Ajk_real;
            (((double *)C)[2 * (i * ldc + j)]) += alpha_real * prod_real - alpha_imag * prod_imag;
            (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * prod_imag + alpha_imag * prod_real;
        }
    }
}
}
