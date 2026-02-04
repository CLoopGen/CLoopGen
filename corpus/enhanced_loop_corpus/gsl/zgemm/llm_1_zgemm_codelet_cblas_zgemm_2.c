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
        const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
        const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
        const double temp_real = alpha_real * Fik_real - alpha_imag * Fik_imag;
        const double temp_imag = alpha_real * Fik_imag + alpha_imag * Fik_real;
        if (!(temp_real == 0. && temp_imag == 0.)) {
            double *C_row = &(((double *)C)[2 * (ldc * i)]);
            const double *G_k = &(((const double *)G)[2 * (ldg * k)]);
            for (j = 0; j < n2; j++) {
                const double Gkj_real = G_k[2 * j];
                const double Gkj_imag = conjG * G_k[2 * j + 1];
                C_row[2 * j]     += temp_real * Gkj_real - temp_imag * Gkj_imag;
                C_row[2 * j + 1] += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
