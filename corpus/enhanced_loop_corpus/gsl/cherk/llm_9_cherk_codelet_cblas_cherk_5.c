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
    for (j = i; j < N; j += 4) {
        float temp_real[4] = {0.}, temp_imag[4] = {0.};
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);

            if (j < N) {
                const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
                const float Ajk0_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
                temp_real[0] += Aik_real * Ajk0_real - Aik_imag * Ajk0_imag;
                temp_imag[0] += Aik_real * Ajk0_imag + Aik_imag * Ajk0_real;
            }
            if (j+1 < N) {
                const float Ajk1_real = (((const float *)A)[2 * ((j+1) * lda + k)]);
                const float Ajk1_imag = -(((const float *)A)[2 * ((j+1) * lda + k) + 1]);
                temp_real[1] += Aik_real * Ajk1_real - Aik_imag * Ajk1_imag;
                temp_imag[1] += Aik_real * Ajk1_imag + Aik_imag * Ajk1_real;
            }
            if (j+2 < N) {
                const float Ajk2_real = (((const float *)A)[2 * ((j+2) * lda + k)]);
                const float Ajk2_imag = -(((const float *)A)[2 * ((j+2) * lda + k) + 1]);
                temp_real[2] += Aik_real * Ajk2_real - Aik_imag * Ajk2_imag;
                temp_imag[2] += Aik_real * Ajk2_imag + Aik_imag * Ajk2_real;
            }
            if (j+3 < N) {
                const float Ajk3_real = (((const float *)A)[2 * ((j+3) * lda + k)]);
                const float Ajk3_imag = -(((const float *)A)[2 * ((j+3) * lda + k) + 1]);
                temp_real[3] += Aik_real * Ajk3_real - Aik_imag * Ajk3_imag;
                temp_imag[3] += Aik_real * Ajk3_imag + Aik_imag * Ajk3_real;
            }
        }
        if (j < N) {
            (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real[0];
            (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag[0];
        }
        if (j+1 < N) {
            (((float *)C)[2 * (i * ldc + j+1)]) += alpha * temp_real[1];
            (((float *)C)[2 * (i * ldc + j+1) + 1]) += alpha * temp_imag[1];
        }
        if (j+2 < N) {
            (((float *)C)[2 * (i * ldc + j+2)]) += alpha * temp_real[2];
            (((float *)C)[2 * (i * ldc + j+2) + 1]) += alpha * temp_imag[2];
        }
        if (j+3 < N) {
            (((float *)C)[2 * (i * ldc + j+3)]) += alpha * temp_real[3];
            (((float *)C)[2 * (i * ldc + j+3) + 1]) += alpha * temp_imag[3];
        }
    }
}
}
