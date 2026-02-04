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
        float acc_real = 0.0f;
        float acc_imag = 0.0f;
        for (k = 0; k < K; k++) {
            const float Fki_real = (((const float *)F)[2 * (ldf * k + i)]);
            const float Fki_imag = conjF * (((const float *)F)[2 * (ldf * k + i) + 1]);
            const float Gkj_real = (((const float *)G)[2 * (ldg * k + j)]);
            const float Gkj_imag = conjG * (((const float *)G)[2 * (ldg * k + j) + 1]);
            const float prod_real = Fki_real * Gkj_real - Fki_imag * Gkj_imag;
            const float prod_imag = Fki_real * Gkj_imag + Fki_imag * Gkj_real;
            acc_real += prod_real;
            acc_imag += prod_imag;
        }
        acc_real *= alpha_real;
        acc_imag = alpha_real * acc_imag + alpha_imag * acc_real; // Modified: Fuse alpha with accumulated result differently
        (((float *)C)[2 * (ldc * i + j)]) += acc_real;
        (((float *)C)[2 * (ldc * i + j) + 1]) += acc_imag;
    }
}
}
