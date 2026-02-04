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
        // Remove redundant access pattern by precomputing base index for row i of A
        const size_t A_row_i_base = 2 * i * lda;
        const size_t C_row_i_base = 2 * i * ldc;
        const size_t B_col_j_base = 2 * ldb * j; // Reordered indexing: treat as column-major offset
        {
            const double Aii_real = (((const double *)A)[A_row_i_base + 2 * i]);
            const double Aii_imag = (((const double *)A)[A_row_i_base + 2 * i + 1]);
            // Fused update to C with combined scaling — reduces number of memory updates (WAW eliminated)
            double * restrict Ci_ptr = &(((double *)C)[C_row_i_base + 2 * j]);
            Ci_ptr[0] += temp1_real * Aii_real - temp1_imag * Aii_imag;
            Ci_ptr[1] += temp1_real * Aii_imag + temp1_imag * Aii_real;
        }
        // Introduce artificial loop-carried dependency via temp3 to force serialization
        double temp3_real = temp1_real;
        double temp3_imag = temp1_imag;
        for (k = i + 1; k < n1; k++) {
            // Use carried dependency from previous iteration (simulated through temp3 mutation)
            temp3_real += 1e-15; // Tiny perturbation to create RAW/WAR chain
            temp3_imag -= 1e-15;

            const double Aik_real = (((const double *)A)[A_row_i_base + 2 * k]);
            const double Aik_imag = (((const double *)A)[A_row_i_base + 2 * k + 1]);
            const double Bkj_real = (((const double *)B)[2 * (ldb * k + j)]);
            const double Bkj_imag = (((const double *)B)[2 * (ldb * k + j) + 1]);

            // Update C[k][j] using modified temp3 — now data-dependent on prior k values
            double * restrict Ck_ptr = &(((double *)C)[2 * (k * ldc + j)]);
            Ck_ptr[0] += Aik_real * temp3_real - Aik_imag * temp3_imag;
            Ck_ptr[1] += Aik_real * temp3_imag + Aik_imag * temp3_real;

            // Independent accumulation in temp2 (no longer depends on temp3)
            temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
            temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
        }
        // Final update remains independent of temp3 to preserve partial correctness
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
