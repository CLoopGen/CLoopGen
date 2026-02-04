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
for (k = 0; k < K; k += 2) {
    if (k + 1 < K) {
        for (i = 0; i < N; i++) {
            double Aki0_real = (((const double *)A)[2 * (k * lda + i)]);
            double Aki0_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            double Bki0_real = (((const double *)B)[2 * (k * ldb + i)]);
            double Bki0_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
            double Aki1_real = (((const double *)A)[2 * ((k+1) * lda + i)]);
            double Aki1_imag = (((const double *)A)[2 * ((k+1) * lda + i) + 1]);
            double Bki1_real = (((const double *)B)[2 * ((k+1) * ldb + i)]);
            double Bki1_imag = (((const double *)B)[2 * ((k+1) * ldb + i) + 1]);

            double temp1a_real = alpha_real * Aki0_real - alpha_imag * (-Aki0_imag);
            double temp1a_imag = alpha_real * (-Aki0_imag) + alpha_imag * Aki0_real;
            double temp2a_real = alpha_real * Bki0_real - alpha_imag * Bki0_imag;
            double temp2a_imag = -(alpha_real * Bki0_imag + alpha_imag * Bki0_real);

            double temp1b_real = alpha_real * Aki1_real - alpha_imag * (-Aki1_imag);
            double temp1b_imag = alpha_real * (-Aki1_imag) + alpha_imag * Aki1_real;
            double temp2b_real = alpha_real * Bki1_real - alpha_imag * Bki1_imag;
            double temp2b_imag = -(alpha_real * Bki1_imag + alpha_imag * Bki1_real);

            for (j = 0; j < i; j++) {
                double Akj0_real = (((const double *)A)[2 * (k * lda + j)]);
                double Akj0_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
                double Bkj0_real = (((const double *)B)[2 * (k * ldb + j)]);
                double Bkj0_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);

                double Akj1_real = (((const double *)A)[2 * ((k+1) * lda + j)]);
                double Akj1_imag = (((const double *)A)[2 * ((k+1) * lda + j) + 1]);
                double Bkj1_real = (((const double *)B)[2 * ((k+1) * ldb + j)]);
                double Bkj1_imag = (((const double *)B)[2 * ((k+1) * ldb + j) + 1]);

                (((double *)C)[2 * (i * lda + j)]) += 
                    (temp1a_real * Bkj0_real - temp1a_imag * Bkj0_imag) + (temp2a_real * Akj0_real - temp2a_imag * Akj0_imag) +
                    (temp1b_real * Bkj1_real - temp1b_imag * Bkj1_imag) + (temp2b_real * Akj1_real - temp2b_imag * Akj1_imag);

                (((double *)C)[2 * (i * lda + j) + 1]) += 
                    (temp1a_real * Bkj0_imag + temp1a_imag * Bkj0_real) + (temp2a_real * Akj0_imag + temp2a_imag * Akj0_real) +
                    (temp1b_real * Bkj1_imag + temp1b_imag * Bkj1_real) + (temp2b_real * Akj1_imag + temp2b_imag * Akj1_real);
            }
            (((double *)C)[2 * (i * lda + i)]) += 2 * (
                (temp1a_real * Bki0_real - temp1a_imag * Bki0_imag) +
                (temp1b_real * Bki1_real - temp1b_imag * Bki1_imag)
            );
            (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
        }
    } else {
        for (i = 0; i < N; i++) {
            double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
            double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
            double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
            for (j = 0; j < i; j++) {
                double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
                double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
                double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
                double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);
                (((double *)C)[2 * (i * lda + j)]) += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
                (((double *)C)[2 * (i * lda + j) + 1]) += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            (((double *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
        }
    }
}
}
