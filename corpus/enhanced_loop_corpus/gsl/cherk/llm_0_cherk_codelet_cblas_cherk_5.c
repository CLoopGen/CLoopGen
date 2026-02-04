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
    float temp_real_inner;
    float temp_imag_inner;
    for (j = i; j < N; j++) {
        temp_real_inner = 0.;
        temp_imag_inner = 0.;
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real_inner += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag_inner += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real_inner;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag_inner;
    }
}
}
