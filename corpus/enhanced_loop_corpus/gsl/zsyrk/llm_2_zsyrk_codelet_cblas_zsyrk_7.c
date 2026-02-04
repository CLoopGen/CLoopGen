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
    for (j = 0; j <= i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *A_ptr = (const double *)A;
        for (k = 0; k < K; k++) {
            int index_i = 2 * (k * lda + i);
            int index_j = 2 * (k * lda + j);
            const double Aki_real = A_ptr[index_i];
            const double Aki_imag = A_ptr[index_i + 1];
            const double Akj_real = A_ptr[index_j];
            const double Akj_imag = A_ptr[index_j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        double *C_ptr = (double *)C;
        int idx_c = 2 * (i * ldc + j);
        C_ptr[idx_c]   += alpha_real * temp_real - alpha_imag * temp_imag;
        C_ptr[idx_c+1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
