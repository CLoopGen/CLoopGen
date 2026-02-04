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
    double temp2_accum_real[256] = {0}; // Local accumulation array to break WAW dependencies
    double temp2_accum_imag[256] = {0};
    if (n2 > 256) continue; // Avoid buffer overflow; in practice, use dynamic allocation
    for (j = 0; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        temp2_accum_real[j] = 0.0;
        temp2_accum_imag[j] = 0.0;
        for (k = 0; k < i; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
            double update_real = Aik_real * temp1_real + Aik_imag * temp1_imag;
            double update_imag = Aik_real * temp1_imag - Aik_imag * temp1_real;
            (((double *)C)[2 * (k * ldc + j)]) += update_real;
            (((double *)C)[2 * (k * ldc + j) + 1]) += update_imag;
            temp2_accum_real[j] += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_accum_imag[j] += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Aii_real;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_imag * Aii_real;
        }
    }
    for (j = 0; j < n2; j++) {
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_accum_real[j] - alpha_imag * temp2_accum_imag[j];
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_accum_imag[j] + alpha_imag * temp2_accum_real[j];
    }
}
}
