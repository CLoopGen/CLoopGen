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
for (k = 0; k < K; k += 2) {
    if (k + 1 < K) {
        for (i = 0; i < N; i++) {
            // Load A(k,i), A(k+1,i), B(k,i), B(k+1,i)
            double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            double Ak1i_real = (((const double *)A)[2 * ((k+1) * lda + i)]);
            double Ak1i_imag = (((const double *)A)[2 * ((k+1) * lda + i) + 1]);
            double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
            double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
            double Bk1i_real = (((const double *)B)[2 * ((k+1) * ldb + i)]);
            double Bk1i_imag = (((const double *)B)[2 * ((k+1) * ldb + i) + 1]);

            double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
            double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
            double temp1k1_real = alpha_real * Ak1i_real - alpha_imag * Ak1i_imag;
            double temp1k1_imag = alpha_real * Ak1i_imag + alpha_imag * Ak1i_real;

            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
            double temp2k1_real = alpha_real * Bk1i_real - alpha_imag * Bk1i_imag;
            double temp2k1_imag = alpha_real * Bk1i_imag + alpha_imag * Bk1i_real;

            for (j = 0; j <= i; j++) {
                double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
                double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
                double Ak1j_real = (((const double *)A)[2 * ((k+1) * lda + j)]);
                double Ak1j_imag = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);
                double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
                double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);
                double Bk1j_real = (((const double *)B)[2 * ((k+1) * ldb + j)]);
                double Bk1j_imag = (((const double *)B)[2 * ((k+1) * ldb + j) + 1]);

                // Accumulate C(i,j) using both k and k+1
                double sum_real = (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                                  (temp2_real * Akj_real - temp2_imag * Akj_imag) +
                                  (temp1k1_real * Bk1j_real - temp1k1_imag * Bk1j_imag) +
                                  (temp2k1_real * Ak1j_real - temp2k1_imag * Ak1j_imag);

                double sum_imag = (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                                  (temp2_real * Akj_imag + temp2_imag * Akj_real) +
                                  (temp1k1_real * Bk1j_imag + temp1k1_imag * Bk1j_real) +
                                  (temp2k1_real * Ak1j_imag + temp2k1_imag * Ak1j_real);

                (((double *)C)[2 * (i * lda + j)]) += sum_real;
                (((double *)C)[2 * (i * lda + j) + 1]) += sum_imag;
            }
        }
    } else {
        // Handle last odd k
        for (i = 0; i < N; i++) {
            double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
            double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
            double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
            double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
            for (j = 0; j <= i; j++) {
                double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
                double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
                double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
                double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);
                (((double *)C)[2 * (i * lda + j)]) += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
                (((double *)C)[2 * (i * lda + j) + 1]) += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
        }
    }
}
}
