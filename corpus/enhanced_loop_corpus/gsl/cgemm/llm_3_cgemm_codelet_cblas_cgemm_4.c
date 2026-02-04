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
    const float* Fk_base = &(((const float *)F)[2 * ldf * k]);
    const float* Gk_base = &(((const float *)G)[2 * ldg * k]);
    for (i = 0; i < n1; i++) {
        const float Fki_real = Fk_base[2 * i];
        const float Fki_imag = conjF * Fk_base[2 * i + 1];
        const float temp_real = alpha_real * Fki_real - alpha_imag * Fki_imag;
        const float temp_imag = alpha_real * Fki_imag + alpha_imag * Fki_real;
        if (!(temp_real == 0. && temp_imag == 0.)) {
            for (j = 0; j < n2; j++) {
                const float Gkj_real = Gk_base[2 * j];
                const float Gkj_imag = conjG * Gk_base[2 * j + 1];
                float* Cij = &(((float *)C)[2 * (ldc * i + j)]);
                Cij[0] += temp_real * Gkj_real - temp_imag * Gkj_imag;
                Cij[1] += temp_real * Gkj_imag + temp_imag * Gkj_real;
            }
        }
    }
}
}
