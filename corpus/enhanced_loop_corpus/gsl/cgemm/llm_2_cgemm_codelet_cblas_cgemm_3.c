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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const int base_i = ldf * i;
        const int base_j = ldg * j;
        for (k = 0; k < K; k++) {
            const float Fik_real = ((const float*)F)[2 * (base_i + k)];
            const float Fik_imag = conjF * ((const float*)F)[2 * (base_i + k) + 1];
            const float Gjk_real = ((const float*)G)[2 * (base_j + k)];
            const float Gjk_imag = conjG * ((const float*)G)[2 * (base_j + k) + 1];
            temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
        }
        const int c_index = 2 * (ldc * i + j);
        ((float*)C)[c_index] += alpha_real * temp_real - alpha_imag * temp_imag;
        ((float*)C)[c_index + 1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
