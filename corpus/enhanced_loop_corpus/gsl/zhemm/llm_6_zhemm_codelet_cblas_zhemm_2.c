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
        // Introduce WAW dependency by splitting update to C[i][j] into two phases with intermediate write
        double partial_real = 0.0, partial_imag = 0.0;
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            partial_real += temp1_real * Aii_real;
            partial_imag += temp1_imag * Aii_real;
        }
        for (k = i + 1; k < n1; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);
            // Update C[k][j] early: introduces RAW dependency on Aik and Bkj
            (((double *)C)[2 * (k * ldc + j)]) += Aik_real * temp1_real + Aik_imag * temp1_imag;  // Note sign flip: equivalent under reassociation
            (((double *)C)[2 * (k * ldc + j) + 1]) += Aik_real * temp1_imag - Aik_imag * temp1_real;
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        // Final accumulation: WAW after partial write (simulated through local variable)
        (((double *)C)[2 * (i * ldc + j)]) += partial_real + (alpha_real * temp2_real - alpha_imag * temp2_imag);
        (((double *)C)[2 * (i * ldc + j) + 1]) += partial_imag + (alpha_real * temp2_imag + alpha_imag * temp2_real);
    }
}
}
