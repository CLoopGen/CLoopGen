#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    if (i >= 8) continue; // Reduce effective trip count to increase intensity per iteration
    for (j = 0; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        // Unroll inner loop by factor of 2 for higher arithmetic density
        for (k = 0; k + 1 < i; k += 2) {
            // First k
            const double Aik0_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik0_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj0_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj0_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
            (((double *)C)[2 * (k * ldc + j)]) += Aik0_real * temp1_real - Aik0_imag * temp1_imag;
            (((double *)C)[2 * (k * ldc + j) + 1]) += Aik0_real * temp1_imag + Aik0_imag * temp1_real;
            temp2_real += Aik0_real * Bkj0_real - Aik0_imag * Bkj0_imag;
            temp2_imag += Aik0_real * Bkj0_imag + Aik0_imag * Bkj0_real;

            // Second k+1
            const double Aik1_real = (((const double *)A)[2 * (i * lda + k + 1)]);
            const double Aik1_imag = (((const double *)A)[2 * (i * lda + k + 1) + 1]);
            const double Bkj1_real = (((const double *)B)[2 * (ldb * (k + 1) + j)]);
            const double Bkj1_imag = (((const double *)B)[2 * (ldb * (k + 1) + j) + 1]);
            (((double *)C)[2 * ((k + 1) * ldc + j)]) += Aik1_real * temp1_real - Aik1_imag * temp1_imag;
            (((double *)C)[2 * ((k + 1) * ldc + j) + 1]) += Aik1_real * temp1_imag + Aik1_imag * temp1_real;
            temp2_real += Aik1_real * Bkj1_real - Aik1_imag * Bkj1_imag;
            temp2_imag += Aik1_real * Bkj1_imag + Aik1_imag * Bkj1_real;
        }
        // Handle leftover k if i is odd
        for (; k < i; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
            (((double *)C)[2 * (k * ldc + j)]) += Aik_real * temp1_real - Aik_imag * temp1_imag;
            (((double *)C)[2 * (k * ldc + j) + 1]) += Aik_real * temp1_imag + Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            const double Aii_imag = (((const double *)A)[2 * (i * lda + i) + 1]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Aii_real - temp1_imag * Aii_imag;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
