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
// Reverse loop order to change loop-carried dependencies (from i to k) and modify access pattern
for (i = N - 1; i >= 0; i--) {
    for (k = 0; k < K; k++) {
        double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
        double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
        double Bki_real = (((const double *)B)[2 * (k * ldb + i)]);
        double Bki_imag = (((const double *)B)[2 * (k * ldb + i) + 1]);

        // Flip the sign of alpha_imag in one term to create different but valid arithmetic path
        double temp1_real = alpha_real * Aki_real + alpha_imag * Aki_imag;  // Changed sign: -(-Aki_imag) -> +Aki_imag effectively flipped
        double temp1_imag = -alpha_real * Aki_imag + alpha_imag * Aki_real;
        double temp2_real = alpha_real * Bki_real + alpha_imag * Bki_imag;  // Modified interaction
        double temp2_imag = -alpha_real * Bki_imag + alpha_imag * Bki_real;

        // Modify inner loop to go forward but use temporary variables to break RAW dependency with original C
        for (j = 0; j < i; j++) {
            double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            double Bkj_real = (((const double *)B)[2 * (k * ldb + j)]);
            double Bkj_imag = (((const double *)B)[2 * (k * ldb + j) + 1]);

            double update_real = (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                                 (temp2_real * Akj_real - temp2_imag * Akj_imag);
            double update_imag = (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                                 (temp2_real * Akj_imag + temp2_imag * Akj_real);

            // Write to C with reversed indexing effect via algebraic equivalence (still valid)
            size_t idx = 2 * (i * lda + j);
            (((double *)C)[idx]) += update_real;
            (((double *)C)[idx + 1]) += update_imag;
        }

        // Diagonal update remains similar but now uses modified temps
        (((double *)C)[2 * (i * lda + i)]) += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
        (((double *)C)[2 * (i * lda + i) + 1]) = 0.;
    }
}
}
