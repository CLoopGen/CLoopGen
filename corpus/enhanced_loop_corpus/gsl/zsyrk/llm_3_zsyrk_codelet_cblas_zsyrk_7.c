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
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *base_A = (const double *)A;
        for (k = 0; k < K; k++) {
            int offset_k = k * lda;
            const double Aki_real = base_A[2 * (offset_k + i)];
            const double Aki_imag = base_A[2 * (offset_k + i) + 1];
            const double Akj_real = base_A[2 * (offset_k + j)];
            const double Akj_imag = base_A[2 * (offset_k + j) + 1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        double *C_ptr = (double *)C;
        int c_index = 2 * (i * ldc + j);
        C_ptr[c_index]     += alpha_real * temp_real - alpha_imag * temp_imag;
        C_ptr[c_index + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
