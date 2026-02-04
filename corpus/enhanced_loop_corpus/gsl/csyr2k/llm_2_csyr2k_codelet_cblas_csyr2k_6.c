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
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *A_i = &(((const float *)A)[2 * (i * lda)]);
        const float *B_i = &(((const float *)B)[2 * (i * ldb)]);
        const float *A_j = &(((const float *)A)[2 * (j * lda)]);
        const float *B_j = &(((const float *)B)[2 * (j * ldb)]);
        for (k = 0; k < K; k++) {
            const float Aik_real = A_i[2 * k];
            const float Aik_imag = A_i[2 * k + 1];
            const float Bik_real = B_i[2 * k];
            const float Bik_imag = B_i[2 * k + 1];
            const float Ajk_real = A_j[2 * k];
            const float Ajk_imag = A_j[2 * k + 1];
            const float Bjk_real = B_j[2 * k];
            const float Bjk_imag = B_j[2 * k + 1];
            temp_real += ((Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag));
            temp_imag += ((Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real));
        }
        float *Cij = &(((float *)C)[2 * (i * ldc + j)]);
        Cij[0] += alpha_real * temp_real - alpha_imag * temp_imag;
        Cij[1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
