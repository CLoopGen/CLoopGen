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
    // Variant 2: Strided memory access with structure-of-arrays (SoA) layout simulation
    // Simulate strided access by separating real and imaginary parts into virtual lanes
    // Assume interleaved storage but process real/imag separately with stride = 2
    const double *A_real = (const double *)A;
    const double *A_imag = (const double *)A + 1;
    const double *B_real = (const double *)B;
    const double *B_imag = (const double *)B + 1;
    double *C_real = (double *)C;
    double *C_imag = (double *)C + 1;

    for (k = 0; k < K; k++) {
        for (i = 0; i < N; i++) {
            int a_idx = 2 * (k * lda + i);
            int b_idx = 2 * (k * ldb + i);

            double Aki_real = A_real[a_idx];
            double Aki_imag = A_imag[a_idx];
            double Bki_real = B_real[b_idx];
            double Bki_imag = B_imag[b_idx];

            double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
            double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;

            for (j = i; j < N; j++) {
                int ak_idx = 2 * (k * lda + j);
                int bk_idx = 2 * (k * ldb + j);
                int c_idx = 2 * (i * lda + j);

                double Akj_real = A_real[ak_idx];
                double Akj_imag = A_imag[ak_idx];
                double Bkj_real = B_real[bk_idx];
                double Bkj_imag = B_imag[bk_idx];

                double update_real = (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                                     (temp2_real * Akj_real - temp2_imag * Akj_imag);
                double update_imag = (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                                     (temp2_real * Akj_imag + temp2_imag * Akj_real);

                C_real[c_idx] += update_real;
                C_imag[c_idx] += update_imag;
            }
        }
    }
}
