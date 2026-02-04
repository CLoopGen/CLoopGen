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
// Eliminate loop-carried dependencies by restructuring accumulation into independent partials
// Use two separate accumulators to break potential RAW/WAR chains, then merge at end
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float sum_real_even = 0.;
        float sum_real_odd = 0.;
        float sum_imag_even = 0.;
        float sum_imag_odd = 0.;
        // Split loop into even and odd indices to remove intra-loop dependency
        for (k = 0; k < K; k += 2) {
            // Process even index k
            if (k < K) {
                const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
                const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
                const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
                const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);
                sum_real_even += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
                sum_imag_even += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
            }
            // Process odd index k+1
            if (k + 1 < K) {
                const float Aik1_real = (((const float *)A)[2 * (i * lda + k + 1)]);
                const float Aik1_imag = (((const float *)A)[2 * (i * lda + k + 1) + 1]);
                const float Ajk1_real = (((const float *)A)[2 * (j * lda + k + 1)]);
                const float Ajk1_imag = -(((const float *)A)[2 * (j * lda + k + 1) + 1]);
                sum_real_odd += Aik1_real * Ajk1_real - Aik1_imag * Ajk1_imag;
                sum_imag_odd += Aik1_real * Ajk1_imag + Aik1_imag * Ajk1_real;
            }
        }
        // Merge partial results without interference
        float temp_real = sum_real_even + sum_real_odd;
        float temp_imag = sum_imag_even + sum_imag_odd;
        (((float *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
