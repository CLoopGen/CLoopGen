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
    const int base_i = ldf * i;
    for (k = 0; k < K; k++) {
        const float Fik_real = ((const float*)F)[2 * (base_i + k)];
        const float Fik_imag = conjF * ((const float*)F)[2 * (base_i + k) + 1];
        for (j = 0; j < n2; j++) {
            const int g_index = 2 * (ldg * j + k);
            const float Gjk_real = ((const float*)G)[g_index];
            const float Gjk_imag = conjG * ((const float*)G)[g_index + 1];
            const int c_index = 2 * (ldc * i + j);
            ((float*)C)[c_index]     += alpha_real * (Fik_real * Gjk_real - Fik_imag * Gjk_imag) -
                                        alpha_imag * (Fik_real * Gjk_imag + Fik_imag * Gjk_real);
            ((float*)C)[c_index + 1] += alpha_real * (Fik_real * Gjk_imag + Fik_imag * Gjk_real) +
                                        alpha_imag * (Fik_real * Gjk_real - Fik_imag * Gjk_imag);
        }
    }
}
}
