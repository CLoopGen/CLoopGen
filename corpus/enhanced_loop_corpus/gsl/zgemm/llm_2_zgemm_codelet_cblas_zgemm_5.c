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
        const double *F_i = &((const double *)F)[2 * ldf * i];
        const double *G_j = &((const double *)G)[2 * ldg * j];
        for (k = 0; k < K; k++) {
            const double Fki_real = F_i[2 * k];
            const double Fki_imag = conjF * F_i[2 * k + 1];
            const double Gjk_real = G_j[2 * k];
            const double Gjk_imag = conjG * G_j[2 * k + 1];
            temp_real += Fki_real * Gjk_real - Fki_imag * Gjk_imag;
            temp_imag += Fki_real * Gjk_imag + Fki_imag * Gjk_real;
        }
        double *Cij = &((double *)C)[2 * (ldc * i + j)];
        Cij[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        Cij[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
