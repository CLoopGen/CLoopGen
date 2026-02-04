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
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        // Introduce local accumulation arrays to break false dependencies and allow reordering
        float accum_real[2] = {0.0f, 0.0f};
        float accum_imag[2] = {0.0f, 0.0f};
        int k;
        // Unroll by 2 with partial separation of computations to modify RAW/WAR dependencies
        for (k = 0; k + 1 < K; k += 2) {
            // Process k and k+1 independently to reduce loop-carried dependency chain
            const float Aik0_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik0_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk0_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk0_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);

            const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
            const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
            const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
            const float Ajk1_imag = -(((const float *)A)[2 * (j * lda + k + 1) + 1]);

            accum_real[0] += Aik0_real * Ajk0_real - Aik0_imag * Ajk0_imag;
            accum_imag[0] += Aik0_real * Ajk0_imag + Aik0_imag * Ajk0_real;

            accum_real[1] += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
            accum_imag[1] += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
        }
        // Combine unrolled accumulators
        temp_real = accum_real[0] + accum_real[1];
        temp_imag = accum_imag[0] + accum_imag[1];

        // Handle leftover iteration if K is odd
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
