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
for (j = 0; j < N; j++) {
    for (k = 0; k < K; k++) {
        const float *A_jk = &(((const float *)A)[2 * (j * lda + k)]);
        const float Ajk_real = A_jk[0];
        const float Ajk_imag = A_jk[1];
        for (i = j; i < N; i++) {
            const float *A_ik = &(((const float *)A)[2 * (i * lda + k)]);
            float *C_ij = &(((float *)C)[2 * (i * ldc + j)]);
            const float Aik_real = A_ik[0];
            const float Aik_imag = A_ik[1];
            const float prod_real = Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            const float prod_imag = Aik_real * Ajk_imag + Aik_imag * Ajk_real;
            #pragma omp atomic
            C_ij[0] += alpha_real * prod_real - alpha_imag * prod_imag;
            #pragma omp atomic
            C_ij[1] += alpha_real * prod_imag + alpha_imag * prod_real;
        }
    }
}
}
