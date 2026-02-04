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
    for (j = 0; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;

        // Introduce loop-carried dependency by accumulating across j iterations
        for (k = 0; k < j; k++) {
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            temp2_real += Bik_real * Akj_real + Bik_imag * Akj_imag;
            temp2_imag += Bik_imag * Akj_real - Bik_real * Akj_imag;
        }

        // Update C[j] using accumulated value from previous columns (WAW and RAW dependency introduced)
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;

        // Original update with A[j][j]
        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);
        (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

        // Update off-diagonal elements without changing data flow in k-loop
        for (k = j + 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
        }
    }
}
}
