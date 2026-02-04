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
double *restrict c_ptr = (double *)C;
const double *restrict f_ptr = (const double *)F;
const double *restrict g_ptr = (const double *)G;
for (i = 0; i < n1; i++) {
    for (k = 0; k < K; k++) {
        const ptrdiff_t f_index = 2 * (ldf * i + k);
        const double Fik_real = f_ptr[f_index];
        const double Fik_imag = conjF * f_ptr[f_index + 1];
        const double temp_real = alpha_real * Fik_real - alpha_imag * Fik_imag;
        const double temp_imag = alpha_real * Fik_imag + alpha_imag * Fik_real;
        if (!(temp_real == 0. && temp_imag == 0.)) {
            for (j = 0; j < n2; j++) {
                const ptrdiff_t g_index = 2 * (ldg * k + j);
                const ptrdiff_t c_index = 2 * (ldc * i + j);
                const double Gkj_real = g_ptr[g_index];
                const double Gkj_imag = conjG * g_ptr[g_index + 1];
                c_ptr[c_index]     += temp_real * Gkj_real - temp_imag * Gkj_imag;
                c_ptr[c_index + 1] += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
