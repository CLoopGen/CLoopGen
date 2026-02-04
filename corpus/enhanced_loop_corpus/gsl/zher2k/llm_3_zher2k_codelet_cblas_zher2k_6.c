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
    // Variant 2: Strided memory access reorganized to traverse column-major order in inner loops
    // Improve stride-1 access in C and B by swapping loop order slightly and accessing by columns

    for (i = 0; i < N; i++) {
        for (k = 0; k < K; k++) {
            double Aki_real = ((const double*)A)[2 * (k * lda + i)];
            double Aki_imag = ((const double*)A)[2 * (k * lda + i) + 1];
            double Bki_real = ((const double*)B)[2 * (k * ldb + i)];
            double Bki_imag = ((const double*)B)[2 * (k * ldb + i) + 1];
            double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

            // Diagonal update remains same
            (((double *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
        }

        // Now handle off-diagonal updates with j > i, but access C in increasing column strides
        for (j = i + 1; j < N; j++) {
            double sum_real = 0.0, sum_imag = 0.0;
            for (k = 0; k < K; k++) {
                double Akj_real = ((const double*)A)[2 * (k * lda + j)];
                double Akj_imag = ((const double*)A)[2 * (k * lda + j) + 1];
                double Bkj_real = ((const double*)B)[2 * (k * ldb + j)];
                double Bkj_imag = ((const double*)B)[2 * (k * ldb + j) + 1];

                // Reuse Aki/Bki equivalent from outer i-loop, but now k is inner
                double Aki_real = ((const double*)A)[2 * (k * lda + i)];
                double Aki_imag = ((const double*)A)[2 * (k * lda + i) + 1];
                double Bki_real = ((const double*)B)[2 * (k * ldb + i)];
                double Bki_imag = ((const double*)B)[2 * (k * ldb + i) + 1];

                double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
                double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
                double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
                double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

                sum_real += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                            (temp2_real * Akj_real - temp2_imag * Akj_imag);
                sum_imag += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                            (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            // Accumulate into C[i][j]
            (((double *)C)[2 * (i * lda + j)]) += sum_real;
            (((double *)C)[2 * (i * lda + j) + 1]) += sum_imag;
        }
    }
}
