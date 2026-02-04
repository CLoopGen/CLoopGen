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
    for (k = 0; k < K; k++) {
        const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
        const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
        for (j = i; j < N; j++) {
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            const double prod_real = Aki_real * Akj_real - Aki_imag * Akj_imag;
            const double prod_imag = Aki_real * Akj_imag + Aki_imag * Akj_real;
            (((double *)C)[2 * (i * ldc + j)]) += alpha_real * prod_real - alpha_imag * prod_imag;
            (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * prod_imag + alpha_imag * prod_real;
        }
    }
}
}
