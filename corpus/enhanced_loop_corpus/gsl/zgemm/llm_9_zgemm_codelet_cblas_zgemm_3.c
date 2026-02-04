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
// Increase computational intensity by blocking/tiling the outer loops to improve cache reuse
const int block = 8;
for (int ii = 0; ii < n1; ii += block) {
    for (int jj = 0; jj < n2; jj += block) {
        for (int i = ii; i < ii + block && i < n1; i++) {
            for (int j = jj; j < jj + block && j < n2; j++) {
                double temp_real = 0.;
                double temp_imag = 0.;
                for (k = 0; k < K; k++) {
                    const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
                    const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
                    const double Gjk_real = (((const double *)G)[2 * (ldg * j + k)]);
                    const double Gjk_imag = conjG * (((const double *)G)[2 * (ldg * j + k) + 1]);
                    temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
                    temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
                }
                (((double *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
                (((double *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
            }
        }
    }
}
}
