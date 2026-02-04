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
    // Variant 2: Strided Memory Access Pattern with Reverse Loop Order
    // Change access pattern to stride through arrays in reverse order (j from i-1 down to 0)
    // Also reorganize indexing to emphasize strided, non-consecutive traversal
    for (k = 0; k < K; k++) {
        for (i = 0; i < N; i++) {
            size_t Ak_offset = 2 * (k * lda + i);
            size_t Bk_offset = 2 * (k * ldb + i);
            double Aki_real = ((const double *)A)[Ak_offset];
            double Aki_imag = ((const double *)A)[Ak_offset + 1];
            double Bki_real = ((const double *)B)[Bk_offset];
            double Bki_imag = ((const double *)B)[Bk_offset + 1];
            double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
            // Reverse inner loop: j from i-1 down to 0 (strided backward access)
            for (j = i - 1; j >= 0; j--) {
                size_t Akj_offset = 2 * (k * lda + j);
                size_t Bkj_offset = 2 * (k * ldb + j);
                double Akj_real = ((const double *)A)[Akj_offset];
                double Akj_imag = ((const double *)A)[Akj_offset + 1];
                double Bkj_real = ((const double *)B)[Bkj_offset];
                double Bkj_imag = ((const double *)B)[Bkj_offset + 1];
                size_t Cij_offset = 2 * (i * lda + j);
                ((double *)C)[Cij_offset]     += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
                ((double *)C)[Cij_offset + 1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            size_t Cii_offset = 2 * (i * lda + i);
            ((double *)C)[Cii_offset]     += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            ((double *)C)[Cii_offset + 1] = 0.;
        }
    }
}
