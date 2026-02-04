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
        const float Fki_real = (((const float *)F)[2 * (ldf * k + i)]);
        const float Fki_imag = conjF * (((const float *)F)[2 * (ldf * k + i) + 1]);
        const float temp_real = alpha_real * Fki_real - alpha_imag * Fki_imag;
        const float temp_imag = alpha_real * Fki_imag + alpha_imag * Fki_real;
        for (j = 0; j < n2; j++) {
            const float Gkj_real = (((const float *)G)[2 * (ldg * k + j)]);
            const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j) + 1]);
            float update_real = temp_real * Gkj_real - temp_imag * Gkj_imag;
            float update_imag = temp_real * Gkj_imag + temp_imag * Gkj_real;
            (((float *)C)[2 * (ldc * i + j)]) += update_real;
            (((float *)C)[2 * (ldc * i + j) + 1]) += update_imag;
        }
    }
}
}
