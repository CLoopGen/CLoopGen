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
for (k = 0; k < K / 2; k++) {
    for (i = 0; i < n1; i++) {
        const double Fki_real_0 = (((const double *)F)[2 * (ldf * (2*k) + i)]);
        const double Fki_imag_0 = conjF * (((const double *)F)[2 * (ldf * (2*k) + i) + 1]);
        const double temp_real_0 = alpha_real * Fki_real_0 - alpha_imag * Fki_imag_0;
        const double temp_imag_0 = alpha_real * Fki_imag_0 + alpha_imag * Fki_real_0;

        const double Fki_real_1 = (((const double *)F)[2 * (ldf * (2*k+1) + i)]);
        const double Fki_imag_1 = conjF * (((const double *)F)[2 * (ldf * (2*k+1) + i) + 1]);
        const double temp_real_1 = alpha_real * Fki_real_1 - alpha_imag * Fki_imag_1;
        const double temp_imag_1 = alpha_real * Fki_imag_1 + alpha_imag * Fki_real_1;

        int update_needed_0 = !(temp_real_0 == 0. && temp_imag_0 == 0.);
        int update_needed_1 = !(temp_real_1 == 0. && temp_imag_1 == 0.);

        if (update_needed_0 || update_needed_1) {
            for (j = 0; j < n2; j++) {
                const double Gkj_real_0 = (((const double *)G)[2 * (ldg * (2*k) + j)]);
                const double Gkj_imag_0 = conjG * (((const double *)G)[2 * (ldg * (2*k) + j) + 1]);
                const double Gkj_real_1 = (((const double *)G)[2 * (ldg * (2*k+1) + j)]);
                const double Gkj_imag_1 = conjG * (((const double *)G)[2 * (ldg * (2*k+1) + j) + 1]);

                if (update_needed_0) {
                    (((double *)C)[2 * (ldc * i + j)]) += temp_real_0 * Gkj_real_0 - temp_imag_0 * Gkj_imag_0;
                    (((double *)C)[2 * (ldc * i + j) + 1]) += temp_real_0 * Gkj_imag_0 + temp_imag_0 * Gkj_real_0;
                }

                if (update_needed_1) {
                    (((double *)C)[2 * (ldc * i + j)]) += temp_real_1 * Gkj_real_1 - temp_imag_1 * Gkj_imag_1;
                    (((double *)C)[2 * (ldc * i + j) + 1]) += temp_real_1 * Gkj_imag_1 + temp_imag_1 * Gkj_real_1;
                }
            }
        }
    }
}
if (K % 2 == 1) {
    k = K - 1;
    for (i = 0; i < n1; i++) {
        const double Fki_real = (((const double *)F)[2 * (ldf * k + i)]);
        const double Fki_imag = conjF * (((const double *)F)[2 * (ldf * k + i) + 1]);
        const double temp_real = alpha_real * Fki_real - alpha_imag * Fki_imag;
        const double temp_imag = alpha_real * Fki_imag + alpha_imag * Fki_real;
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
