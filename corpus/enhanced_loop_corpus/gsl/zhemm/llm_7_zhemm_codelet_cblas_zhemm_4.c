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
    double temp2_real_cache = 0.;
    double temp2_imag_cache = 0.;
    // Hoist j=0 special case to break uniform loop-carried pattern and vary data flow
    if (n2 > 0) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + 0)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + 0) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;

        const double Ajj_real = (((const double *)A)[2 * (0 * lda + 0)]);
        (((double *)C)[2 * (i * ldc + 0)]) += temp1_real * Ajj_real;
        (((double *)C)[2 * (i * ldc + 0) + 1]) += temp1_imag * Ajj_real;

        double local_temp2_real = 0.;
        double local_temp2_imag = 0.;

        for (k = 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (0 * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (0 * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);

            // Eliminate redundant negation: simplify arithmetic expression
            double product_real = temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            double product_imag = temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            // Remove WAW hazard by deferring write until after read in same iteration
            double current_Ckr = (((double *)C)[2 * (i * ldc + k)]);
            double current_Cki = (((double *)C)[2 * (i * ldc + k) + 1]);

            (((double *)C)[2 * (i * ldc + k)]) = current_Ckr + product_real;
            (((double *)C)[2 * (i * ldc + k) + 1]) = current_Cki + product_imag;

            // Modify dependency: reverse sign logic for symmetry variation
            local_temp2_real += Bik_real * Ajk_real + Bik_imag * Ajk_imag;
            local_temp2_imag += -Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        temp2_real_cache = local_temp2_real;
        temp2_imag_cache = local_temp2_imag;
    }

    // Continue from j=1 onward, reusing cached temp2-like contributions indirectly
    for (j = 1; j < n2; j++) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;

        const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
        (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_imag * Ajj_real;

        for (k = j + 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);

            double update_real = temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            double update_imag = temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            // Direct accumulation without intermediate variables — stronger WAW/RAW
            (((double *)C)[2 * (i * ldc + k)]) += update_real;
            (((double *)C)[2 * (i * ldc + k) + 1]) += update_imag;

            // Independent of above: compute temp2 contribution but do not reuse across j
            double term_real = Bik_real * Ajk_real - Bik_imag * (-Ajk_imag);
            double term_imag = Bik_real * (-Ajk_imag) + Bik_imag * Ajk_real;
            temp2_real_cache += term_real;
            temp2_imag_cache += term_imag;
        }
    }
    // Apply delayed global update only once per i (loop-carried dependency introduced)
    if (n2 > 0) {
        (((double *)C)[2 * (i * ldc + 0)]) += alpha_real * temp2_real_cache - alpha_imag * temp2_imag_cache;
        (((double *)C)[2 * (i * ldc + 0) + 1]) += alpha_real * temp2_imag_cache + alpha_imag * temp2_real_cache;
    }
}
}
