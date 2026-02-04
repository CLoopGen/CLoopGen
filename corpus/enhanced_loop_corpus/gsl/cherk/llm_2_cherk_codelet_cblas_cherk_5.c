#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *A_i = &((const float *)A)[2 * (i * lda)];
        const float *A_j = &((const float *)A)[2 * (j * lda)];
        for (k = 0; k < K; k++) {
            const float Aik_real = A_i[2 * k];
            const float Aik_imag = A_i[2 * k + 1];
            const float Ajk_real = A_j[2 * k];
            const float Ajk_imag = -A_j[2 * k + 1];
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        float *Cij = &((float *)C)[2 * (i * ldc + j)];
        Cij[0] += alpha * temp_real;
        Cij[1] += alpha * temp_imag;
    }
}
}
