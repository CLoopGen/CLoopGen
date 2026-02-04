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
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i += 2) {
        if (i + 1 >= N) break;
        double Aki_real_0 = (((const double *)A)[2 * (k * lda + i)]);
        double Aki_imag_0 = (((const double *)A)[2 * (k * lda + i) + 1]);
        double Bki_real_0 = (((const double *)B)[2 * (k * ldb + i)]);
        double Bki_imag_0 = (((const double *)B)[2 * (k * ldb + i) + 1]);
        double temp1_real_0 = alpha_real * Aki_real_0 - alpha_imag * (-Aki_imag_0);
        double temp1_imag_0 = alpha_real * (-Aki_imag_0) + alpha_imag * Aki_real_0;
        double temp2_real_0 = alpha_real * Bki_real_0 - alpha_imag * Bki_imag_0;
        double temp2_imag_0 = -(alpha_real * Bki_imag_0 + alpha_imag * Bki_real_0);

        double Aki_real_1 = (((const double *)A)[2 * (k * lda + i + 1)]);
        double Aki_imag_1 = (((const double *)A)[2 * (k * lda + i + 1) + 1]);
        double Bki_real_1 = (((const double *)B)[2 * (k * ldb + i + 1)]);
        double Bki_imag_1 = (((const double *)B)[2 * (k * ldb + i + 1) + 1]);
        double temp1_real_1 = alpha_real * Aki_real_1 - alpha_imag * (-Aki_imag_1);
        double temp1_imag_1 = alpha_real * (-Aki_imag_1) + alpha_imag * Aki_real_1;
        double temp2_real_1 = alpha_real * Bki_real_1 - alpha_imag * Bki_imag_1;
        double temp2_imag_1 = -(alpha_real * Bki_imag_1 + alpha_imag * Bki_real_1);

        {
            (((double *)C)[2 * (i * lda + i)]) += 2 * (temp1_real_0 * Bki_real_0 - temp1_imag_0 * Bki_imag_0);
            (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
            (((double *)C)[2 * ((i+1) * lda + (i+1))]) += 2 * (temp1_real_1 * Bki_real_1 - temp1_imag_1 * Bki_imag_1);
            (((double *)C)[2 * ((i+1) * lda + (i+1)) + 1]) = 0.;
        }
        for (j = i + 1; j < N; j++) {
            double Akj_real_0 = (((const double *)A)[2 * (k * lda + j)]);
            double Akj_imag_0 = (((const double *)A)[2 * (k * lda + j) + 1]);
            double Bkj_real_0 = (((const double *)B)[2 * (k * ldb + j)]);
            double Bkj_imag_0 = (((const double *)B)[2 * (k * ldb + j) + 1]);

            (((double *)C)[2 * (i * lda + j)]) += (temp1_real_0 * Bkj_real_0 - temp1_imag_0 * Bkj_imag_0) + (temp2_real_0 * Akj_real_0 - temp2_imag_0 * Akj_imag_0);
            (((double *)C)[2 * (i * lda + j) + 1]) += (temp1_real_0 * Bkj_imag_0 + temp1_imag_0 * Bkj_real_0) + (temp2_real_0 * Akj_imag_0 + temp2_imag_0 * Akj_real_0);

            (((double *)C)[2 * ((i+1) * lda + j)]) += (temp1_real_1 * Bkj_real_0 - temp1_imag_1 * Bkj_imag_0) + (temp2_real_1 * Akj_real_0 - temp2_imag_1 * Akj_imag_0);
            (((double *)C)[2 * ((i+1) * lda + j) + 1]) += (temp1_real_1 * Bkj_imag_0 + temp1_imag_1 * Bkj_real_0) + (temp2_real_1 * Akj_imag_0 + temp2_imag_1 * Akj_real_0);
        }
    }
}
}
