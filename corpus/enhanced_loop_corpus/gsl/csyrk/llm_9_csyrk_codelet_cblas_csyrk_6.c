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
for (i = 0; i < N; i += 2) { // Increase i-loop stride to reduce total iterations
    for (j = 0; j <= i; j++) {
        float temp_real[2] = {0.}, temp_imag[2] = {0.};
        // Process current i and i+1 if valid (loop skewing and unrolling in i)
        const int process_i1 = (i + 1 < N);
        for (k = 0; k < K; k++) {
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);

            temp_real[0] += Aik0_real * Ajk_real - Aik0_imag * Ajk_imag;
            temp_imag[0] += Aik0_real * Ajk_imag + Aik0_imag * Ajk_real;

            if (process_i1) {
                const float Aik1_real = (((const float *)A)[2 * ((i+1) * lda + k)]);
                const float Aik1_imag = (((const float *)A)[2 * ((i+1) * lda + k) + 1]);
                temp_real[1] += Aik1_real * Ajk_real - Aik1_imag * Ajk_imag;
                temp_imag[1] += Aik1_real * Ajk_imag + Aik1_imag * Ajk_real;
            }
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real[0] - alpha_imag * temp_imag[0];
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag[0] + alpha_imag * temp_real[0];

        if (process_i1 && j <= i+1) {
            (((float *)C)[2 * ((i+1) * ldc + j)]) += alpha_real * temp_real[1] - alpha_imag * temp_imag[1];
            (((float *)C)[2 * ((i+1) * ldc + j) + 1]) += alpha_real * temp_imag[1] + alpha_imag * temp_real[1];
        }
    }
}
}
