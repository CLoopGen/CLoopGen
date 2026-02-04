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
for (k = 0; k < K; k += 2) {
    const int k_end = (k + 1 < K) ? k + 2 : k + 1;
    for (i = 0; i < n1; i++) {
        const float Fik0_real = (((const float *)F)[2 * (ldf * i + k)]);
        const float Fik0_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
        const float temp0_real = alpha_real * Fik0_real - alpha_imag * Fik0_imag;
        const float temp0_imag = alpha_real * Fik0_imag + alpha_imag * Fik0_real;
        const int need_second = (k + 1 < K);
        float temp1_real = 0.0f, temp1_imag = 0.0f;
        if (need_second) {
            const float Fik1_real = (((const float *)F)[2 * (ldf * i + k + 1)]);
            const float Fik1_imag = conjF * (((const float *)F)[2 * (ldf * i + k + 1) + 1]);
            temp1_real = alpha_real * Fik1_real - alpha_imag * Fik1_imag;
            temp1_imag = alpha_real * Fik1_imag + alpha_imag * Fik1_real;
        }
        if (!(temp0_real == 0. && temp0_imag == 0.) || (need_second && !(temp1_real == 0. && temp1_imag == 0.))) {
            for (j = 0; j < n2; j++) {
                const float Gkj0_real = (((const float *)G)[2 * (ldg * k + j)]);
                const float Gkj0_imag = conjG * (((const float *)G)[2 * (ldg * k + j) + 1]);
                (((float *)C)[2 * (ldc * i + j)]) += temp0_real * Gkj0_real - temp0_imag * Gkj0_imag;
                (((float *)C)[2 * (ldc * i + j) + 1]) += temp0_real * Gkj0_imag + temp0_imag * Gkj0_real;

                if (need_second) {
                    const float Gkj1_real = (((const float *)G)[2 * (ldg * (k + 1) + j)]);
                    const float Gkj1_imag = conjG * (((const float *)G)[2 * (ldg * (k + 1) + j) + 1]);
                    (((float *)C)[2 * (ldc * i + j)]) += temp1_real * Gkj1_real - temp1_imag * Gkj1_imag;
                    (((float *)C)[2 * (ldc * i + j) + 1]) += temp1_real * Gkj1_imag + temp1_imag * Gkj1_real;
                }
            }
        }
    }
}
}
