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
if (n1 <= 0 || n2 <= 0 || K <= 0) return;
double *c_ptr = (double *)C;
const double *f_base = (const double *)F;
const double *g_base = (const double *)G;
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        int f_offset = ldf * i;
        int g_offset = ldg * j;
        for (k = 0; k < K; k++) {
            const double Fik_real = f_base[2 * (f_offset + k)];
            const double Fik_imag = conjF * f_base[2 * (f_offset + k) + 1];
            const double Gjk_real = g_base[2 * (g_offset + k)];
            const double Gjk_imag = conjG * g_base[2 * (g_offset + k) + 1];
            temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
        }
        int c_index = 2 * (ldc * i + j);
        c_ptr[c_index]     += alpha_real * temp_real - alpha_imag * temp_imag;
        c_ptr[c_index + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
