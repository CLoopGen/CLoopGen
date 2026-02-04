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
// Modify data dependency structure: reverse loop order to change loop-carried dependencies
// and introduce read-after-write (RAW) dependencies across iterations.
// This variant reverses the k-loop to create backward dependence patterns.
for (k = K - 1; k >= 0; k--) {
    for (i = 0; i < N; i++) {
        // Reuse intermediate values with modified computation ordering
        const double *Ak_row = (const double *)A + 2 * (k * lda);
        const double *Bk_row = (const double *)B + 2 * (k * ldb);
        double Aki_real = Ak_row[2 * i];
        double Aki_imag = Ak_row[2 * i + 1];
        double Bki_real = Bk_row[2 * i];
        double Bki_imag = Bk_row[2 * i + 1];
        double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
        for (j = 0; j <= i; j++) {
            double Akj_real = Ak_row[2 * j];
            double Akj_imag = Ak_row[2 * j + 1];
            double Bkj_real = Bk_row[2 * j];
            double Bkj_imag = Bk_row[2 * j + 1];
            // Update C in a fused manner but now influenced by reverse-k access pattern
            // introducing different memory reuse and potential cache effects
            double *Cij = &(((double *)C)[2 * (i * lda + j)]);
            Cij[0] += temp1_real * Bkj_real - temp1_imag * Bkj_imag + temp2_real * Akj_real - temp2_imag * Akj_imag;
            Cij[1] += temp1_real * Bkj_imag + temp1_imag * Bkj_real + temp2_real * Akj_imag + temp2_imag * Akj_real;
        }
    }
}
}
