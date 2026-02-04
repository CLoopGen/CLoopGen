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
        const double *F_row = &((const double *)F)[2 * (ldf * i + k)];
        const double Fik_real = F_row[0];
        const double Fik_imag = conjF * F_row[1];
        for (j = 0; j < n2; j++) {
            const double *G_col = &((const double *)G)[2 * (ldg * j + k)];
            const double Gjk_real = G_col[0];
            const double Gjk_imag = conjG * G_col[1];
            double temp_real = Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            double temp_imag = Fik_real * Gjk_imag + Fik_imag * Gjk_real;
            (((double *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
            (((double *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
        }
    }
}
}
