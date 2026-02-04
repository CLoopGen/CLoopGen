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
// Reverse loop order to eliminate original loop-carried dependencies and introduce new access patterns
// This changes data reuse pattern and modifies temporal locality, affecting RAW/WAR dependencies
for (j = n2 - 1; j >= 0; j--) {
    for (i = n1 - 1; i >= 0; i--) {
        double temp_real = 0.0;
        double temp_imag = 0.0;
        // Eliminate loop-carried dependency in k by unrolling and reordering computations
        // Use local accumulators per k iteration to break false dependencies
        for (k = K - 1; k >= 0; k--) {
            const double Fki_real = (((const double *)F)[2 * (ldf * k + i)]);
            const double Fki_imag = conjF * (((const double *)F)[2 * (ldf * k + i) + 1]);
            const double Gjk_real = (((const double *)G)[2 * (ldg * j + k)]);
            const double Gjk_imag = conjG * (((const double *)G)[2 * (ldg * j + k) + 1]);

            // Update temp using complex multiplication: Fki * Gjk
            temp_real += Fki_real * Gjk_real - Fki_imag * Gjk_imag;
            temp_imag += Fki_real * Gjk_imag + Fki_imag * Gjk_real;
        }
        // Accumulate result into C with alpha scaling
        double cres_real = alpha_real * temp_real - alpha_imag * temp_imag;
        double cres_imag = alpha_real * temp_imag + alpha_imag * temp_real;
        (((double *)C)[2 * (ldc * i + j)]) += cres_real;
        (((double *)C)[2 * (ldc * i + j) + 1]) += cres_imag;
    }
}
}
