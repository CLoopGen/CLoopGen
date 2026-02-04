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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Introduce local accumulation arrays to break false dependencies and enable reordering
        double accum_real[2] = {0.0, 0.0};
        double accum_imag[2] = {0.0, 0.0};
        for (k = 0; k < K; k += 2) {
            // Process two iterations at once to modify data dependency pattern
            if (k + 1 < K) {
                // First k iteration
                const double Aik0_real = (((const double *)A)[2 * (i * lda + k)]);
                const double Aik0_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
                const double Bik0_real = (((const double *)B)[2 * (i * ldb + k)]);
                const double Bik0_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
                const double Ajk0_real = (((const double *)A)[2 * (j * lda + k)]);
                const double Ajk0_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
                const double Bjk0_real = (((const double *)B)[2 * (j * ldb + k)]);
                const double Bjk0_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);

                // Second k+1 iteration
                const double Aik1_real = (((const double *)A)[2 * (i * lda + k + 1)]);
                const double Aik1_imag = (((const double *)A)[2 * (i * lda + k + 1) + 1]);
                const double Bik1_real = (((const double *)B)[2 * (i * ldb + k + 1)]);
                const double Bik1_imag = (((const double *)B)[2 * (i * ldb + k + 1) + 1]);
                const double Ajk1_real = (((const double *)A)[2 * (j * lda + k + 1)]);
                const double Ajk1_imag = (((const double *)A)[2 * (j * lda + k + 1) + 1]);
                const double Bjk1_real = (((const double *)B)[2 * (j * ldb + k + 1)]);
                const double Bjk1_imag = (((const double *)B)[2 * (j * ldb + k + 1) + 1]);

                // Update both accumulators independently to remove sequential dependency
                accum_real[0] += (Aik0_real * Bjk0_real - Aik0_imag * Bjk0_imag) + (Bik0_real * Ajk0_real - Bik0_imag * Ajk0_imag);
                accum_imag[0] += (Aik0_real * Bjk0_imag + Aik0_imag * Bjk0_real) + (Bik0_real * Ajk0_imag + Bik0_imag * Ajk0_real);

                accum_real[1] += (Aik1_real * Bjk1_real - Aik1_imag * Bjk1_imag) + (Bik1_real * Ajk1_real - Bik1_imag * Ajk1_imag);
                accum_imag[1] += (Aik1_real * Bjk1_imag + Aik1_imag * Bjk1_real) + (Bik1_real * Ajk1_imag + Bik1_imag * Ajk1_real);
            } else {
                // Handle odd K
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
        }
        // Combine partial accumulations
        temp_real += accum_real[0] + accum_real[1];
        temp_imag += accum_imag[0] + accum_imag[1];
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
