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
    double temp_accum_real[64] = {0}; // Local accumulation array to remove write-after-write (WAW) hazards
    double temp_accum_imag[64] = {0};
    const int local_n2 = n2 < 64 ? n2 : 64; // Bound stack allocation

    for (j = 0; j < local_n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;

        // Eliminate loop-carried dependency by privatizing reduction into local arrays
        temp_accum_real[j] = 0.0;
        temp_accum_imag[j] = 0.0;

        for (k = j + 1; k < local_n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);

            // Update C[k] immediately — breaks potential WAR hazard via out-of-order updates
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            // Accumulate partial products locally instead of scalar temp2 (removes WAW across j)
            temp_accum_real[j] += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp_accum_imag[j] += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }

        // Apply diagonal update independently, no longer dependent on k-loop completion
        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);
        (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
    }

    // Final pass: apply delayed accumulations to maintain semantics
    for (j = 0; j < local_n2; j++) {
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_accum_real[j] - alpha_imag * temp_accum_imag[j];
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_accum_imag[j] + alpha_imag * temp_accum_real[j];
    }

    // Handle remaining elements beyond 64 if necessary (fallback)
    for (j = local_n2; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0., temp2_imag = 0.;

        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);
        (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
