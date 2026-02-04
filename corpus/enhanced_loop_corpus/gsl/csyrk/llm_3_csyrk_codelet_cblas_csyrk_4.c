#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        for (j = i; j < N; j++) {
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            float *Cij = &(((float *)C)[2 * (i * ldc + j)]);
            Cij[0] += alpha_real * (Aik_real * Ajk_real - Aik_imag * Ajk_imag);
            Cij[1] += alpha_real * (Aik_real * Ajk_imag + Aik_imag * Ajk_real);
            if (alpha_imag != 0.0f) {
                Cij[0] -= alpha_imag * (Aik_real * Ajk_imag + Aik_imag * Ajk_real);
                Cij[1] += alpha_imag * (Aik_real * Ajk_real - Aik_imag * Ajk_imag);
            }
        }
    }
}
}
