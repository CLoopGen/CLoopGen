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
    for (k = 0; k < K; k++) {
        const double Fki_real = (((const double *)F)[2 * (ldf * k + i)]);
        const double Fki_imag = conjF * (((const double *)F)[2 * (ldf * k + i) + 1]);
        const double temp_real = alpha_real * Fki_real - alpha_imag * Fki_imag;
        const double temp_imag = alpha_real * Fki_imag + alpha_imag * Fki_real;
        if (!(temp_real == 0. && temp_imag == 0.)) {
            const double* Gk_base = &(((const double *)G)[2 * ldg * k]);
            double* Ci_base = &(((double *)C)[2 * (ldc * i)]);
            for (j = 0; j < n2; j++) {
                const double Gkj_real = Gk_base[2 * j];
                const double Gkj_imag = conjG * Gk_base[2 * j + 1];
                Ci_base[2 * j] += temp_real * Gkj_real - temp_imag * Gkj_imag;
                Ci_base[2 * j + 1] += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
