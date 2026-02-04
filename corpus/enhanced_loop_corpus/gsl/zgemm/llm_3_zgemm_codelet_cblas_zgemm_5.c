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
    for (i = 0; i < n1; i++) {
        const double Fki_real = ((const double *)F)[2 * (ldf * k + i)];
        const double Fki_imag = conjF * ((const double *)F)[2 * (ldf * k + i) + 1];
        for (j = 0; j < n2; j++) {
            const double Gjk_real = ((const double *)G)[2 * (ldg * j + k)];
            const double Gjk_imag = conjG * ((const double *)G)[2 * (ldg * j + k) + 1];
            double *Cij = &((double *)C)[2 * (ldc * i + j)];
            double val_real = Fki_real * Gjk_real - Fki_imag * Gjk_imag;
            double val_imag = Fki_real * Gjk_imag + Fki_imag * Gjk_real;
            Cij[0] += alpha_real * val_real - alpha_imag * val_imag;
            Cij[1] += alpha_real * val_imag + alpha_imag * val_real;
        }
    }
}
}
