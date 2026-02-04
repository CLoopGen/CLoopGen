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
for (k = 0; k < K; k += 2) {
    if (k + 1 < K) {
        for (i = 0; i < n1; i++) {
            const double Fik0_real = (((const double *)F)[2 * (ldf * i + k)]);
            const double Fik0_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
            const double temp0_real = alpha_real * Fik0_real - alpha_imag * Fik0_imag;
            const double temp0_imag = alpha_real * Fik0_imag + alpha_imag * Fik0_real;

            const double Fik1_real = (((const double *)F)[2 * (ldf * i + k + 1)]);
            const double Fik1_imag = conjF * (((const double *)F)[2 * (ldf * i + k + 1) + 1]);
            const double temp1_real = alpha_real * Fik1_real - alpha_imag * Fik1_imag;
            const double temp1_imag = alpha_real * Fik1_imag + alpha_imag * Fik1_real;

            const int active0 = !(temp0_real == 0. && temp0_imag == 0.);
            const int active1 = !(temp1_real == 0. && temp1_imag == 0.);

            for (j = 0; j < n2; j++) {
                const double Gkj0_real = (((const double *)G)[2 * (ldg * k + j)]);
                const double Gkj0_imag = conjG * (((const double *)G)[2 * (ldg * k + j) + 1]);
                const double Gkj1_real = (((const double *)G)[2 * (ldg * (k + 1) + j)]);
                const double Gkj1_imag = conjG * (((const double *)G)[2 * (ldg * (k + 1) + j) + 1]);

                if (active0) {
                    (((double *)C)[2 * (ldc * i + j)]) += temp0_real * Gkj0_real - temp0_imag * Gkj0_imag;
                    (((double *)C)[2 * (ldc * i + j) + 1]) += temp0_real * Gkj0_imag + temp0_imag * Gkj0_real;
                }
                if (active1) {
                    (((double *)C)[2 * (ldc * i + j)]) += temp1_real * Gkj1_real - temp1_imag * Gkj1_imag;
                    (((double *)C)[2 * (ldc * i + j) + 1]) += temp1_real * Gkj1_imag + temp1_imag * Gkj1_real;
                }
            }
        }
    } else {
        for (i = 0; i < n1; i++) {
            const double Fik_real = (((const double *)F)[2 * (ldf * i + k)]);
            const double Fik_imag = conjF * (((const double *)F)[2 * (ldf * i + k) + 1]);
            const double temp_real = alpha_real * Fik_real - alpha_imag * Fik_imag;
            const double temp_imag = alpha_real * Fik_imag + alpha_imag * Fik_real;
            if (!(temp_real == 0. && temp_imag == 0.)) {
                for (j = 0; j < n2; j++) {
                    const double Gkj_real = (((const double *)G)[2 * (ldg * k + j)]);
                    const double Gkj_imag = conjG * (((const double *)G)[2 * (ldg * k + j) + 1]);
                    (((double *)C)[2 * (ldc * i + j)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                    (((double *)C)[2 * (ldc * i + j) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
                }
            }
        }
    }
}
}
