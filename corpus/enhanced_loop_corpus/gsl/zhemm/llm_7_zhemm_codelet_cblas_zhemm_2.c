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
        // Remove immediate update of C[i][j], defer all writes to end — eliminates partial WAW
        // Add artificial loop-carried dependency via cumulative scalar across k-loop
        double acc_real = 0.0, acc_imag = 0.0;
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            acc_real = temp1_real * Aii_real;
            acc_imag = temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
            // Introduce WAR-like pattern by updating C[k][j] before using Bkj in reduction
            double ckr_old = (((double *)C)[2 * (k * ldc + j)]);
            double cki_old = (((double *)C)[2 * (k * ldc + j) + 1]);
            // Overwrite C[k][j] before completing temp2 computation → creates WAR if reordered
            (((double *)C)[2 * (k * ldc + j)]) = ckr_old + (Aik_real * temp1_real - (-Aik_imag) * temp1_imag);
            (((double *)C)[2 * (k * ldc + j) + 1]) = cki_old + (Aik_real * temp1_imag + (-Aik_imag) * temp1_real);
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        // Finalize both contributions at once — stronger loop-carried dependence due to late write
        const double final_real = alpha_real * temp2_real - alpha_imag * temp2_imag;
        const double final_imag = alpha_real * temp2_imag + alpha_imag * temp2_real;
        (((double *)C)[2 * (i * ldc + j)]) += acc_real + final_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += acc_imag + final_imag;
    }
}
}
