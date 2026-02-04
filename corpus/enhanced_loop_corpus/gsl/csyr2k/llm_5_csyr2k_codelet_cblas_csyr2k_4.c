#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        k = 0;
        if (K > 0) {
            for (; k < K; k++) {
                const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
                const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
                const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
                const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
                const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
                const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
                const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
                const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);

                float term1_real = Aik_real * Bjk_real - Aik_imag * Bjk_imag;
                float term1_imag = Aik_real * Bjk_imag + Aik_imag * Bjk_real;
                float term2_real = Bik_real * Ajk_real - Bik_imag * Ajk_imag;
                float term2_imag = Bik_real * Ajk_imag + Bik_imag * Ajk_real;

                if (term1_real > -1e-6f || term2_real > -1e-6f) {
                    temp_real += term1_real + term2_real;
                    temp_imag += term1_imag + term2_imag;
                }
            }
        }
        float Cres = (((float *)C)[2 * (i * ldc + j)]);
        float Cimag = (((float *)C)[2 * (i * ldc + j) + 1]);
        (((float *)C)[2 * (i * ldc + j)]) = Cres + (alpha_real * temp_real - alpha_imag * temp_imag);
        (((float *)C)[2 * (i * ldc + j) + 1]) = Cimag + (alpha_real * temp_imag + alpha_imag * temp_real);
    }
}
}
