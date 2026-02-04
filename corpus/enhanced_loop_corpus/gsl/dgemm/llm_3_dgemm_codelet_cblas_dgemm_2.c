#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  double alpha;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  double *F;
extern  double *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const ptrdiff_t c_base = (ptrdiff_t)C;
const ptrdiff_t f_base = (ptrdiff_t)F;
const ptrdiff_t g_base = (ptrdiff_t)G;

for (k = 0; k < K; k++) {
    const double alpha_g = alpha * G[ldg * k];
    if (alpha_g != 0.) {
        for (i = 0; i < n1; i++) {
            const double temp = alpha_g * F[ldf * i + k];
            if (temp != 0.) {
                double * restrict c_row = (double *)(c_base + ldc * i * sizeof(double));
                const double * restrict g_row = (const double *)(g_base + ldg * k * sizeof(double));
                for (j = 0; j < n2; j += 4) {
                    c_row[j]     += temp * g_row[j];
                    if (j+1 < n2) c_row[j+1] += temp * g_row[j+1];
                    if (j+2 < n2) c_row[j+2] += temp * g_row[j+2];
                    if (j+3 < n2) c_row[j+3] += temp * g_row[j+3];
                }
            }
        }
    }
}
}
