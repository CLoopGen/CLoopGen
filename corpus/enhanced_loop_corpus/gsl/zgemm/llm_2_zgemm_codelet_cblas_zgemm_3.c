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
        const double *Fi_base = &(((const double *)F)[2 * ldf * i]);
        const double *Gj_base = &(((const double *)G)[2 * ldg * j]);
        for (k = 0; k < K; k++) {
            const double Fik_real = Fi_base[2 * k];
            const double Fik_imag = conjF * Fi_base[2 * k + 1];
            const double Gjk_real = Gj_base[2 * k];
            const double Gjk_imag = conjG * Gj_base[2 * k + 1];
            temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
        }
        double *Cij = &(((double *)C)[2 * (ldc * i + j)]);
        Cij[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        Cij[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
