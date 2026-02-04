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
extern  float *F;
extern  float *G;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (i = 0; i < n1; i++) {
        const float Fik_real = (((const float *)F)[2 * (ldf * i + k)]);
        const float Fik_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
        const float temp_real = alpha_real * Fik_real - alpha_imag * Fik_imag;
        const float temp_imag = alpha_real * Fik_imag + alpha_imag * Fik_real;
        if (!(temp_real == 0. && temp_imag == 0.)) {
            j = 0;
            for (; j < n2; j += 4) {
                int j1 = j, j2 = j+1, j3 = j+2, j4 = j+3;
                if (j1 < n2) {
                    const float Gkj_real = (((const float *)G)[2 * (ldg * k + j1)]);
                    const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j1) + 1]);
                    (((float *)C)[2 * (ldc * i + j1)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                    (((float *)C)[2 * (ldc * i + j1) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
                }
                if (j2 < n2) {
                    const float Gkj_real = (((const float *)G)[2 * (ldg * k + j2)]);
                    const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j2) + 1]);
                    (((float *)C)[2 * (ldc * i + j2)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                    (((float *)C)[2 * (ldc * i + j2) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
                }
                if (j3 < n2) {
                    const float Gkj_real = (((const float *)G)[2 * (ldg * k + j3)]);
                    const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j3) + 1]);
                    (((float *)C)[2 * (ldc * i + j3)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                    (((float *)C)[2 * (ldc * i + j3) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
                }
                if (j4 < n2) {
                    const float Gkj_real = (((const float *)G)[2 * (ldg * k + j4)]);
                    const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j4) + 1]);
                    (((float *)C)[2 * (ldc * i + j4)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                    (((float *)C)[2 * (ldc * i + j4) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
                }
            }
        }
    }
}
}
