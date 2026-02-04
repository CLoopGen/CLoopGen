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
extern double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K && N > 0; k++) {
    for (i = 0; i < N; i++) {
        double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
        double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
        double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
        double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
        double temp1_real = alpha_real * Aki_real + alpha_imag * Aki_imag;
        double temp1_imag = alpha_real * Aki_imag - alpha_imag * Aki_real;
        double temp2_real = alpha_real * Bki_real + alpha_imag * Bki_imag;
        double temp2_imag = alpha_real * Bki_imag - alpha_imag * Bki_real;

        double update_diag_real = 2.0 * (temp1_real * Bki_real + temp1_imag * Bki_imag);
        (((double *)C)[2 * (i * lda + i)]) += update_diag_real;
        (((double *)C)[2 * (i * lda + i) + 1]) = 0.0;

        for (j = i + 1; j < N; j += 2) {
            double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
            double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);

            double prod1_real = temp1_real * Bkj_real + temp1_imag * Bkj_imag;
            double prod1_imag = temp1_real * Bkj_imag - temp1_imag * Bkj_real;
            double prod2_real = temp2_real * Akj_real + temp2_imag * Akj_imag;
            double prod2_imag = temp2_real * Akj_imag - temp2_imag * Akj_real;

            (((double *)C)[2 * (i * lda + j)]) += prod1_real + prod2_real;
            (((double *)C)[2 * (i * lda + j) + 1]) += prod1_imag + prod2_imag;

            if (j + 1 < N) {
                double Akj1_real = (((const double *)A)[2 * (k * lda + j + 1)]);
                double Akj1_imag = (((const double *)A)[2 * (k * lda + j + 1) + 1]);
                double Bkj1_real = (((const double *)B)[2 * (k * ldb + j + 1)]);
                double Bkj1_imag = (((const double *)B)[2 * (k * ldb + j + 1) + 1]);

                double prod1b_real = temp1_real * Bkj1_real + temp1_imag * Bkj1_imag;
                double prod1b_imag = temp1_real * Bkj1_imag - temp1_imag * Bkj1_real;
                double prod2b_real = temp2_real * Akj1_real + temp2_imag * Akj1_imag;
                double prod2b_imag = temp2_real * Akj1_imag - temp2_imag * Akj1_real;

                (((double *)C)[2 * (i * lda + j + 1)]) += prod1b_real + prod2b_real;
                (((double *)C)[2 * (i * lda + j + 1) + 1]) += prod1b_imag + prod2b_imag;
            }
        }
    }
}
}
