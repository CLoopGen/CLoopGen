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
    const float* Fk = &((const float*)F)[2 * ldf * k];
    const float* Gk = &((const float*)G)[2 * ldg * k];
    for (i = 0; i < n1; i++) {
        const float Fki_real = Fk[2 * i];
        const float Fki_imag = conjF * Fk[2 * i + 1];
        for (j = 0; j < n2; j++) {
            const float Gjk_real = Gk[2 * j];
            const float Gjk_imag = conjG * Gk[2 * j + 1];
            float* Cij = &((float*)C)[2 * (ldc * i + j)];
            Cij[0] += alpha_real * (Fki_real * Gjk_real - Fki_imag * Gjk_imag) - 
                      alpha_imag * (Fki_real * Gjk_imag + Fki_imag * Gjk_real);
            Cij[1] += alpha_real * (Fki_real * Gjk_imag + Fki_imag * Gjk_real) + 
                      alpha_imag * (Fki_real * Gjk_real - Fki_imag * Gjk_imag);
        }
    }
}
}
