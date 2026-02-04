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
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const double *Aki_base = &(((const double *)A)[2 * (k * lda)]);
            const double *Akj_base = Aki_base;
            const double Aki_real = Aki_base[2 * i];
            const double Aki_imag = -Aki_base[2 * i + 1];
            const double Akj_real = Akj_base[2 * j];
            const double Akj_imag = Akj_base[2 * j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        double *Cij = &(((double *)C)[2 * (i * ldc + j)]);
        Cij[0] += alpha * temp_real;
        Cij[1] += alpha * temp_imag;
    }
}
}
