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
        const float* F_base = &((const float*)F)[2 * ldf * i];
        const float* G_base = &((const float*)G)[2 * ldg * j];
        for (k = 0; k < K; k++) {
            const float Fki_real = F_base[2 * k];
            const float Fki_imag = conjF * F_base[2 * k + 1];
            const float Gjk_real = G_base[2 * k];
            const float Gjk_imag = conjG * G_base[2 * k + 1];
            temp_real += Fki_real * Gjk_real - Fki_imag * Gjk_imag;
            temp_imag += Fki_real * Gjk_imag + Fki_imag * Gjk_real;
        }
        float* Cij = &((float*)C)[2 * (ldc * i + j)];
        Cij[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        Cij[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
