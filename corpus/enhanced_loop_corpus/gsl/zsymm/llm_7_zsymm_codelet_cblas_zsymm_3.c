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
    double temp_C_update_real[64], temp_C_update_imag[64]; // Local accumulation to break RAW/WAR
    int max_j = (n2 < 64) ? n2 : 64; // Limit for local buffer
    for (j = 0; j < max_j; j++) {
        temp_C_update_real[j] = 0.0;
        temp_C_update_imag[j] = 0.0;
    }
    for (j = 0; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        // Remove loop-carried dependency on C by using private accumulators per thread-like behavior
        for (k = 0; k < i; k++) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);

            // Eliminate direct write to shared C — instead accumulate contribution locally in temp
            double c_contrib_real = Aik_real * temp1_real - Aik_imag * temp1_imag;
            double c_contrib_imag = Aik_real * temp1_imag + Aik_imag * temp1_real;

            // Simulate privatization: defer global write
            if (j < 64) {
                temp_C_update_real[j] += c_contrib_real;
                temp_C_update_imag[j] += c_contrib_imag;
            } else {
                ((double*)C)[2 * (k * ldc + j)] += c_contrib_real;
                ((double*)C)[2 * (k * ldc + j) + 1] += c_contrib_imag;
            }

            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        {
            const double Aii_real = (((const double *)A)[2 * (i * lda + i)]);
            const double Aii_imag = (((const double *)A)[2 * (i * lda + i) + 1]);
            double diag_update_real = temp1_real * Aii_real - temp1_imag * Aii_imag;
            double diag_update_imag = temp1_real * Aii_imag + temp1_imag * Aii_real;
            ((double*)C)[2 * (i * ldc + j)] += diag_update_real;
            ((double*)C)[2 * (i * ldc + j) + 1] += diag_update_imag;
        }
        ((double*)C)[2 * (i * ldc + j)] += alpha_real * temp2_real - alpha_imag * temp2_imag;
        ((double*)C)[2 * (i * ldc + j) + 1] += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
    // Flush local updates at row level to simulate delayed write-back (reducing RAW pressure)
    for (j = 0; j < max_j; j++) {
        for (k = 0; k < i; k++) {
            ((double*)C)[2 * (k * ldc + j)] += temp_C_update_real[j];
            ((double*)C)[2 * (k * ldc + j) + 1] += temp_C_update_imag[j];
        }
    }
}
}
