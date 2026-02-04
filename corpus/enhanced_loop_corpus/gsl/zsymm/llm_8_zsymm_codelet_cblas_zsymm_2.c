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
for (i = 0; i < n1; i += 2) {
    if (i + 1 >= n1) break;
    for (j = 0; j < n2; j++) {
        const double Bij0_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij0_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_0_real = alpha_real * Bij0_real - alpha_imag * Bij0_imag;
        const double temp1_0_imag = alpha_real * Bij0_imag + alpha_imag * Bij0_real;
        const double Bij1_real = (((const double *)B)[2 * (ldb * (i+1) + j)]);
        const double Bij1_imag = (((const double *)B)[2 * (ldb * (i+1) + j) + 1]);
        const double temp1_1_real = alpha_real * Bij1_real - alpha_imag * Bij1_imag;
        const double temp1_1_imag = alpha_real * Bij1_imag + alpha_imag * Bij1_real;

        double temp2_0_real = 0., temp2_0_imag = 0.;
        double temp2_1_real = 0., temp2_1_imag = 0.;

        {
            const double Aii0_real = (((const double *)A)[2 * (i * lda + i)]);
            const double Aii0_imag = (((const double *)A)[2 * (i * lda + i) + 1]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_0_real * Aii0_real - temp1_0_imag * Aii0_imag;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_0_real * Aii0_imag + temp1_0_imag * Aii0_real;

            const double Aii1_real = (((const double *)A)[2 * ((i+1) * lda + (i+1))]);
            const double Aii1_imag = (((const double *)A)[2 * ((i+1) * lda + (i+1)) + 1]);
            (((double *)C)[2 * ((i+1) * ldc + j)]) += temp1_1_real * Aii1_real - temp1_1_imag * Aii1_imag;
            (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += temp1_1_real * Aii1_imag + temp1_1_imag * Aii1_real;
        }

        for (k = i + 1; k < n1; k++) {
            const double Aik0_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik0_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Aik1_real = (((const double *)A)[2 * ((i+1) * lda + k)]);
            const double Aik1_imag = (((const double *)A)[2 * ((i+1) * lda + k) + 1]);

            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);

            (((double *)C)[2 * (k * ldc + j)]) += Aik0_real * temp1_0_real - Aik0_imag * temp1_0_imag;
            (((double *)C)[2 * (k * ldc + j) + 1]) += Aik0_real * temp1_0_imag + Aik0_imag * temp1_0_real;

            (((double *)C)[2 * (k * ldc + j)]) += Aik1_real * temp1_1_real - Aik1_imag * temp1_1_imag;
            (((double *)C)[2 * (k * ldc + j) + 1]) += Aik1_real * temp1_1_imag + Aik1_imag * temp1_1_real;

            temp2_0_real += Aik0_real * Bkj_real - Aik0_imag * Bkj_imag;
            temp2_0_imag += Aik0_real * Bkj_imag + Aik0_imag * Bkj_real;

            temp2_1_real += Aik1_real * Bkj_real - Aik1_imag * Bkj_imag;
            temp2_1_imag += Aik1_real * Bkj_imag + Aik1_imag * Bkj_real;
        }

        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_0_real - alpha_imag * temp2_0_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_0_imag + alpha_imag * temp2_0_real;

        (((double *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp2_1_real - alpha_imag * temp2_1_imag;
        (((double *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp2_1_imag + alpha_imag * temp2_1_real;
    }
}
}
