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
for (k = 0; k < K; k++) {
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const double Fki_real = (((const double *)F)[2 * (ldf * k + i)]);
            const double Fki_imag = conjF * (((const double *)F)[2 * (ldf * k + i) + 1]);
            const double temp_real = alpha_real * Fki_real - alpha_imag * Fki_imag;
            const double temp_imag = alpha_real * Fki_imag + alpha_imag * Fki_real;
            if (!(temp_real == 0. && temp_imag == 0.)) {
                const double Gkj_real = (((const double *)G)[2 * (ldg * k + j)]);
                const double Gkj_imag = conjG * (((const double *)G)[2 * (ldg * k + j) + 1]);
                (((double *)C)[2 * (ldc * i + j)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                (((double *)C)[2 * (ldc * i + j) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
