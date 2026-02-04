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
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse loop order to eliminate original loop-carried WAW and WAR dependencies
// by processing j from i down to 0, and unroll k with partial redundancy elimination
for (i = 0; i < N; i++) {
    for (j = i; j >= 0; j--) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Unroll k by factor of 2 to change data flow and expose parallelism
        int k = 0;
        for (; k < K - 1; k += 2) {
            // Load values for k and k+1 in an interleaved but independent way
            const double Aik0_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik0_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bik0_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik0_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Ajk0_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk0_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bjk0_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk0_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

            const double Aik1_real = (((const double *)A)[2 * (i * lda + k + 1)]);
            const double Aik1_imag = (((const double *)A)[2 * (i * lda + k + 1) + 1]);
            const double Bik1_real = (((const double *)B)[2 * (i * ldb + k + 1)]);
            const double Bik1_imag = (((const double *)B)[2 * (i * ldb + k + 1) + 1]);
            const double Ajk1_real = (((const double *)A)[2 * (j * lda + k + 1)]);
            const double Ajk1_imag = (((const double *)A)[2 * (j * lda + k + 1) + 1]);
            const double Bjk1_real = (((const double *)B)[2 * (j * ldb + k + 1)]);
            const double Bjk1_imag = (((const double *)B)[2 * (j * ldb + k + 1) + 1]);

            // Compute contributions independently to break RAW chains
            double term1_real = Aik0_real * Bjk0_real - Aik0_imag * Bjk0_imag;
            double term1_imag = Aik0_real * Bjk0_imag + Aik0_imag * Bjk0_real;
            double term2_real = Bik0_real * Ajk0_real - Bik0_imag * Ajk0_imag;
            double term2_imag = Bik0_real * Ajk0_imag + Bik0_imag * Ajk0_real;

            double term3_real = Aik1_real * Bjk1_real - Aik1_imag * Bjk1_imag;
            double term3_imag = Aik1_real * Bjk1_imag + Aik1_imag * Bjk1_real;
            double term4_real = Bik1_real * Ajk1_real - Bik1_imag * Ajk1_imag;
            double term4_imag = Bik1_real * Ajk1_imag + Bik1_imag * Ajk1_real;

            temp_real += (term1_real + term2_real) + (term3_real + term4_real);
            temp_imag += (term1_imag + term2_imag) + (term3_imag + term4_imag);
        }
        // Handle remaining odd element
        for (; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);
            temp_real += ((Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag));
            temp_imag += ((Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real));
        }
        // Update C with accumulated values
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
