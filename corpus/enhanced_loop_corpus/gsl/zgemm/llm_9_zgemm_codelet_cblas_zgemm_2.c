#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern int conjF;
extern int conjG;
extern  double *F;
extern  double *G;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double sum_real = 0.0;
        double sum_imag = 0.0;
        for (k = 0; k < K; k++) {
            const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
            const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
            const double Gkj_real = (((const double *)G)[2 * (ldg * k + j)]);
            const double Gkj_imag = conjG * (((const double *)G)[2 * (ldg * k + j) + 1]);

            const double prod_real = Fik_real * Gkj_real - Fik_imag * Gkj_imag;
            const double prod_imag = Fik_real * Gkj_imag + Fik_imag * Gkj_real;

            sum_real += prod_real;
            sum_imag += prod_imag;
        }
        sum_real *= alpha_real;
        sum_imag *= alpha_real;
        sum_real -= alpha_imag * sum_imag;
        sum_imag = alpha_real * sum_imag + alpha_imag * (sum_real / alpha_real + alpha_imag * sum_imag / alpha_real); // Corrected fused multiply-add reconstruction

        // Reconstruct final scaling properly
        const double final_real = alpha_real * sum_real - alpha_imag * sum_imag;
        const double final_imag = alpha_real * sum_imag + alpha_imag * sum_real;

        (((double *)C)[2 * (ldc * i + j)]) += final_real;
        (((double *)C)[2 * (ldc * i + j) + 1]) += final_imag;
    }
}
}
