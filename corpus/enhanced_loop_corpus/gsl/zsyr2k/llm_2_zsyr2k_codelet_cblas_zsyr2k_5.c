#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering loops and prefetching data
    // Reorder loops to j-i-k to improve spatial locality in C accesses
    double *C_ptr = (double *)C;
    const double *A_ptr = (const double *)A;
    const double *B_ptr = (const double *)B;

    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            double sum_real = 0.0;
            double sum_imag = 0.0;
            for (k = 0; k < K; k++) {
                double Aki_real = A_ptr[2 * (k * lda + i)];
                double Aki_imag = A_ptr[2 * (k * lda + i) + 1];
                double Bki_real = B_ptr[2 * (k * ldb + i)];
                double Bki_imag = B_ptr[2 * (k * ldb + i) + 1];
                double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
                double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
                double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
                double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;

                double Akj_real = A_ptr[2 * (k * lda + j)];
                double Akj_imag = A_ptr[2 * (k * lda + j) + 1];
                double Bkj_real = B_ptr[2 * (k * ldb + j)];
                double Bkj_imag = B_ptr[2 * (k * ldb + j) + 1];

                sum_real += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                            (temp2_real * Akj_real - temp2_imag * Akj_imag);
                sum_imag += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                            (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            int idx = 2 * (i * lda + j);
            C_ptr[idx] += sum_real;
            C_ptr[idx + 1] += sum_imag;
        }
    }
}
