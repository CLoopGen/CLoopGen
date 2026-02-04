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
    for (j = 0; j < n2; j += 2) {
        if (j + 1 >= n2) {
            j = n2 - 1; // Handle leftover column
        }

        double temp1_real[2] = {0}, temp1_imag[2] = {0};
        double temp2_real[2] = {0}, temp2_imag[2] = {0};

        for (int col = 0; col < ((j+1 < n2) ? 2 : 1); col++) {
            const int j_idx = j + col;
            temp1_real[col] = alpha_real * (((const double *)B)[2 * (ldb * i + j_idx)]) 
                            - alpha_imag * (((const double *)B)[2 * (ldb * i + j_idx) + 1]);
            temp1_imag[col] = alpha_real * (((const double *)B)[2 * (ldb * i + j_idx) + 1]) 
                            + alpha_imag * (((const double *)B)[2 * (ldb * i + j_idx)]);
        }

        for (k = 0; k < i; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);

            for (int col = 0; col < ((j+1 < n2) ? 2 : 1); col++) {
                const int j_idx = j + col;
                const double Bkj_real = (((const double *)B)[2 * (ldb * k + j_idx)]);
                const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j_idx) + 1]);

                double *C_ptr = &(((double *)C)[2 * (k * ldc + j_idx)]);
                C_ptr[0] += Aik_real * temp1_real[col] - (-Aik_imag) * temp1_imag[col];
                C_ptr[1] += Aik_real * temp1_imag[col] + (-Aik_imag) * temp1_real[col];

                temp2_real[col] += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
                temp2_imag[col] += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
            }
        }

        const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
        for (int col = 0; col < ((j+1 < n2) ? 2 : 1); col++) {
            const int j_idx = j + col;
            double *C_ptr = &(((double *)C)[2 * (i * ldc + j_idx)]);
            C_ptr[0] += temp1_real[col] * Aii_real;
            C_ptr[1] += temp1_imag[col] * Aii_real;
            C_ptr[0] += alpha_real * temp2_real[col] - alpha_imag * temp2_imag[col];
            C_ptr[1] += alpha_real * temp2_imag[col] + alpha_imag * temp2_real[col];
        }

        if (j + 1 >= n2) break; // Exit if last iteration handled single column
    }
}
}
