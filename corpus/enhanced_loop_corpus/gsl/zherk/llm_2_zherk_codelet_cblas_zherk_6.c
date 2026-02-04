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
    for (j = i; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *A_ptr = (const double *)A;
        for (k = 0; k < K; k++) {
            int idx_i = 2 * (k * lda + i);
            int idx_j = 2 * (k * lda + j);
            const double Aki_real = A_ptr[idx_i];
            const double Aki_imag = -A_ptr[idx_i + 1];
            const double Akj_real = A_ptr[idx_j];
            const double Akj_imag = A_ptr[idx_j + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        double *C_ptr = (double *)C;
        int idx_c = 2 * (i * ldc + j);
        C_ptr[idx_c] += alpha * temp_real;
        C_ptr[idx_c + 1] += alpha * temp_imag;
    }
}
}
