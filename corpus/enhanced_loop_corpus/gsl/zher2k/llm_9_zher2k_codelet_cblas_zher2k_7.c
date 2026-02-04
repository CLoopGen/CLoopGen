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
extern double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by processing only every second row, increasing arithmetic per iteration via partial tiling
for (i = 0; i < N; i += 2) {
    // Process two rows at once if within bounds
    for (j = 0; j < i; j++) {
        double temp_real_0 = 0., temp_imag_0 = 0.;
        double temp_real_1 = 0., temp_imag_1 = 0.;

        for (k = 0; k < K; k++) {
            // Row i computations
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;
            const double Bjk_real = (((const double *)B)[2 * (j * ldb + k)]);
            const double Bjk_imag = (((const double *)B)[2 * (j * ldb + k) + 1]);
            temp_real_0 += ((temp1_real * Bjk_real + temp1_imag * Bjk_imag) + (Bik_real * temp2_real + Bik_imag * temp2_imag));
            temp_imag_0 += ((temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) + (Bik_real * (-temp2_imag) + Bik_imag * temp2_real));

            // Row i+1 (if valid)
            if (i + 1 < N) {
                const double Aik1_real = (((const double *)A)[2 * ((i + 1) * lda + k)]);
                const double Aik1_imag = (((const double *)A)[2 * ((i + 1) * lda + k) + 1]);
                const double temp11_real = alpha_real * Aik1_real - alpha_imag * Aik1_imag;
                const double temp11_imag = alpha_real * Aik1_imag + alpha_imag * Aik1_real;
                const double Bik1_real = (((const double *)B)[2 * ((i + 1) * ldb + k)]);
                const double Bik1_imag = (((const double *)B)[2 * ((i + 1) * ldb + k) + 1]);
                temp_real_1 += ((temp11_real * Bjk_real + temp11_imag * Bjk_imag) + (Bik1_real * temp2_real + Bik1_imag * temp2_imag));
                temp_imag_1 += ((temp11_real * (-Bjk_imag) + temp11_imag * Bjk_real) + (Bik1_real * (-temp2_imag) + Bik1_imag * temp2_real));
            }
        }

        (((double *)C)[2 * (i * ldc + j)]) += temp_real_0;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp_imag_0;

        if (i + 1 < N) {
            (((double *)C)[2 * ((i + 1) * ldc + j)]) += temp_real_1;
            (((double *)C)[2 * ((i + 1) * ldc + j) + 1]) += temp_imag_1;
        }
    }

    // Diagonal update for row i
    {
        double temp_real = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = (((const double *)B)[2 * (i * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * (i * ldb + k) + 1]);
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((double *)C)[2 * (i * ldc + i)]) += 2 * temp_real;
        (((double *)C)[2 * (i * ldc + i) + 1]) = 0.;
    }

    // Diagonal update for row i+1 if valid
    if (i + 1 < N) {
        double temp_real = 0.;
        for (k = 0; k < K; k++) {
            const double Aik_real = (((const double *)A)[2 * ((i + 1) * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * ((i + 1) * lda + k) + 1]);
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double Bik_real = (((const double *)B)[2 * ((i + 1) * ldb + k)]);
            const double Bik_imag = (((const double *)B)[2 * ((i + 1) * ldb + k) + 1]);
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((double *)C)[2 * ((i + 1) * ldc + (i + 1))]) += 2 * temp_real;
        (((double *)C)[2 * ((i + 1) * ldc + (i + 1)) + 1]) = 0.;
    }
}
}
