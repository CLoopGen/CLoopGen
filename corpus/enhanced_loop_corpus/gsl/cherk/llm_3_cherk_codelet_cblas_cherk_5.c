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
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const int idx_ik = 2 * (i * lda + k);
            const int idx_jk = 2 * (j * lda + k);
            const float *A_base = (const float *)A;
            const float Aik_real = A_base[idx_ik];
            const float Aik_imag = A_base[idx_ik + 1];
            const float Ajk_real = A_base[idx_jk];
            const float Ajk_imag = -A_base[idx_jk + 1];
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        float *C_ptr = (float *)C;
        const int idx_c = 2 * (i * ldc + j);
        C_ptr[idx_c] += alpha * temp_real;
        C_ptr[idx_c + 1] += alpha * temp_imag;
    }
}
}
