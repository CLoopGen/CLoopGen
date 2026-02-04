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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float sum_real = 0.0f;
        float sum_imag = 0.0f;
        for (k = 0; k < K; k++) {
            const float Fik_real = (((const float *)F)[2 * (ldf * i + k)]);
            const float Fik_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
            const float Gkj_real = (((const float *)G)[2 * (ldg * k + j)]);
            const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j) + 1]);
            const float prod_real = Fik_real * Gkj_real - Fik_imag * Gkj_imag;
            const float prod_imag = Fik_real * Gkj_imag + Fik_imag * Gkj_real;
            sum_real += prod_real;
            sum_imag += prod_imag;
        }
        const float scaled_real = alpha_real * sum_real - alpha_imag * sum_imag;
        const float scaled_imag = alpha_real * sum_imag + alpha_imag * sum_real;
        (((float *)C)[2 * (ldc * i + j)]) += scaled_real;
        (((float *)C)[2 * (ldc * i + j) + 1]) += scaled_imag;
    }
}
}
