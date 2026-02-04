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
    for (j = 0; j < n2; j++) {
        double temp1_real[2], temp1_imag[2];
        double Bij_real, Bij_imag;
        for (int ii = 0; ii < 2 && (i + ii) < n1; ii++) {
            int idx = i + ii;
            Bij_real = (((const double *)B)[2 * (ldb * idx + j)]);
            Bij_imag = (((const double *)B)[2 * (ldb * idx + j) + 1]);
            temp1_real[ii] = alpha_real * Bij_real - alpha_imag * Bij_imag;
            temp1_imag[ii] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
        for (int ii = 0; ii < 2 && (i + ii) < n1; ii++) {
            int idx = i + ii;
            double temp2_real = 0.;
            double temp2_imag = 0.;
            for (k = 0; k < idx; k++) {
                const double Aik_real = (((const double *)A)[2 * (idx * lda + k)]);
                const double Aik_imag = (((const double *)A)[2 * (idx * lda + k) + 1]);
                const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
                const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
                (((double *)C)[2 * (k * ldc + j)]) += Aik_real * temp1_real[ii] - Aik_imag * temp1_imag[ii];
                (((double *)C)[2 * (k * ldc + j) + 1]) += Aik_real * temp1_imag[ii] + Aik_imag * temp1_real[ii];
                temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
                temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            }
            {
                const double Aii_real = (((const double *)A)[2 * (idx * lda + idx)]);
                const double Aii_imag = (((const double *)A)[2 * (idx * lda + idx) + 1]);
                (((double *)C)[2 * (idx * ldc + j)]) += temp1_real[ii] * Aii_real - temp1_imag[ii] * Aii_imag;
                (((double *)C)[2 * (idx * ldc + j) + 1]) += temp1_real[ii] * Aii_imag + temp1_imag[ii] * Aii_real;
            }
            (((double *)C)[2 * (idx * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
            (((double *)C)[2 * (idx * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
        }
    }
}
}
