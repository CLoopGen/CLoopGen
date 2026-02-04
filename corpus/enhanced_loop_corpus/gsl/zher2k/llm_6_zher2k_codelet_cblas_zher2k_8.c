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
    for (i = 0; i < N; i++) {
        double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
        double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
        double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
        double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);
        double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
        double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
        double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

        // Introduce a local accumulation buffer to remove write-after-write (WAW) dependency on C
        double sum_real = 0.0, sum_imag = 0.0;

        for (j = 0; j < i; j++) {
            double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
            double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);

            sum_real += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
            sum_imag += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
        }

        // Accumulate into C only once per (i,k), reducing WAW and RAW dependencies across iterations
        if (i > 0) {
            (((double *)C)[2 * (i * lda + j - 1)]) += sum_real;
            (((double *)C)[2 * (i * lda + j - 1) + 1]) += sum_imag;
        }

        // Update diagonal element as before
        (((double *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
        (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
    }
}
}
