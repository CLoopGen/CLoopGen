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
for (i = 0; i < N; i++) {
    for (j = 0; j < i; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        const double *Ap_row = &(((const double *)A)[2 * (i * lda)]);
        const double *Bp_row = &(((const double *)B)[2 * (j * ldb)]);
        const double *Ap_col = &(((const double *)A)[2 * (j * lda)]);
        const double *Bp_col = &(((const double *)B)[2 * (i * ldb)]);
        for (k = 0; k < K; k++) {
            const double Aik_real = Ap_row[2 * k];
            const double Aik_imag = Ap_row[2 * k + 1];
            const double Bjk_real = Bp_row[2 * k];
            const double Bjk_imag = Bp_row[2 * k + 1];
            const double Ajk_real = Ap_col[2 * k];
            const double Ajk_imag = Ap_col[2 * k + 1];
            const double Bik_real = Bp_col[2 * k];
            const double Bik_imag = Bp_col[2 * k + 1];

            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            const double temp2_real = alpha_real * Ajk_real - alpha_imag * Ajk_imag;
            const double temp2_imag = alpha_real * Ajk_imag + alpha_imag * Ajk_real;

            temp_real += (temp1_real * Bjk_real + temp1_imag * Bjk_imag) +
                         (Bik_real * temp2_real + Bik_imag * temp2_imag);
            temp_imag += (temp1_real * (-Bjk_imag) + temp1_imag * Bjk_real) +
                         (Bik_real * (-temp2_imag) + Bik_imag * temp2_real);
        }
        (((double *)C)[2 * (i * ldc + j)]) += temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp_imag;
    }
    {
        double temp_real = 0.;
        const double *Ap_row = &(((const double *)A)[2 * (i * lda)]);
        const double *Bp_row = &(((const double *)B)[2 * (i * ldb)]);
        for (k = 0; k < K; k++) {
            const double Aik_real = Ap_row[2 * k];
            const double Aik_imag = Ap_row[2 * k + 1];
            const double Bik_real = Bp_row[2 * k];
            const double Bik_imag = Bp_row[2 * k + 1];
            const double temp1_real = alpha_real * Aik_real - alpha_imag * Aik_imag;
            const double temp1_imag = alpha_real * Aik_imag + alpha_imag * Aik_real;
            temp_real += temp1_real * Bik_real + temp1_imag * Bik_imag;
        }
        (((double *)C)[2 * (i * ldc + i)]) += 2 * temp_real;
        (((double *)C)[2 * (i * ldc + i) + 1]) = 0.;
    }
}
}
