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
        k = 0;
        for (; k < K; k += 2) {
            const double Aki_real1 = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag1 = -(((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real1 = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag1 = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real1 * Akj_real1 - Aki_imag1 * Akj_imag1;
            temp_imag += Aki_real1 * Akj_imag1 + Aki_imag1 * Akj_real1;

            if (k + 1 < K) {
                const double Aki_real2 = (((const double *)A)[2 * ((k+1) * lda + i)]);
                const double Aki_imag2 = -(((const double *)A)[2 * ((k+1) * lda + i) + 1]);
                const double Akj_real2 = (((const double *)A)[2 * ((k+1) * lda + j)]);
                const double Akj_imag2 = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);
                temp_real += Aki_real2 * Akj_real2 - Aki_imag2 * Akj_imag2;
                temp_imag += Aki_real2 * Akj_imag2 + Aki_imag2 * Akj_real2;
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
