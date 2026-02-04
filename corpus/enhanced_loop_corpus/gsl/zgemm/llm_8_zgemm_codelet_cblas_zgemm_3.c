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
        double temp_real = 0.;
        double temp_imag = 0.;
        int k;
        // Unroll loop by factor of 2 to reduce trip count and increase arithmetic per iteration
        for (k = 0; k + 1 < K; k += 2) {
            const double Fik0_real = (((const double *)F)[2 * (ldf * i + k)]);
            const double Fik0_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
            const double Gjk0_real = (((const double *)G)[2 * (ldg * j + k)]);
            const double Gjk0_imag = conjG * (((const double *)G)[2 * (ldg * j + k) + 1]);
            temp_real += Fik0_real * Gjk0_real - Fik0_imag * Gjk0_imag;
            temp_imag += Fik0_real * Gjk0_imag + Fik0_imag * Gjk0_real;

            const double Fik1_real = (((const double *)F)[2 * (ldf * i + k + 1)]);
            const double Fik1_imag = conjF * (((const double *)F)[2 * (ldf * i + k + 1) + 1]);
            const double Gjk1_real = (((const double *)G)[2 * (ldg * j + k + 1)]);
            const double Gjk1_imag = conjG * (((const double *)G)[2 * (ldg * j + k + 1) + 1]);
            temp_real += Fik1_real * Gjk1_real - Fik1_imag * Gjk1_imag;
            temp_imag += Fik1_real * Gjk1_imag + Fik1_imag * Gjk1_real;
        }
        // Handle remaining element if K is odd
        if (k < K) {
            const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
            const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
            const double Gjk_real = (((const double *)G)[2 * (ldg * j + k)]);
            const double Gjk_imag = conjG * (((const double *)G)[2 * (ldg * j + k) + 1]);
            temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
        }
        (((double *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
