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
        for (j = 0; j < n2; j++) {
            if (temp_real != 0. || temp_imag != 0.) {
                const float Gkj_real = (((const float *)G)[2 * (ldg * k + j)]);
                const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j) + 1]);
                (((float *)C)[2 * (ldc * i + j)]) += temp_real * Gkj_real - temp_imag * Gkj_imag;
                (((float *)C)[2 * (ldc * i + j) + 1]) += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
