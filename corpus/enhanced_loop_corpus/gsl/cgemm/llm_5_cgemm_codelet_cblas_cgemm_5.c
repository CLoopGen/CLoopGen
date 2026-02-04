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
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            if (k % 2 == 0) {
                const float Fki_real = (((const float *)F)[2 * (ldf * k + i)]);
                const float Fki_imag = conjF * (((const float *)F)[2 * (ldf * k + i) + 1]);
                const float Gjk_real = (((const float *)G)[2 * (ldg * j + k)]);
                const float Gjk_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);
                temp_real += Fki_real * Gjk_real - Fki_imag * Gjk_imag;
                temp_imag += Fki_real * Gjk_imag + Fki_imag * Gjk_real;
            } else {
                temp_real += 0.0f;
                temp_imag += 0.0f;
            }
        }
        (((float *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
