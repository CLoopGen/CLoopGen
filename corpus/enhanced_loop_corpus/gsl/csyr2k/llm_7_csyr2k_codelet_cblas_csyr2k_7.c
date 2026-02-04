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
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reorganize loop order to eliminate loop-carried dependencies across k by fusing computations
// Introduce temporary cache-like arrays to decouple read/write patterns and change data flow
float *restrict cache_real = (float*)alloca(N * sizeof(float));
float *restrict cache_imag = (float*)alloca(N * sizeof(float));

for (i = 0; i < N; i++) {
    // Initialize local accumulators to remove WAW hazards from multiple k contributions
    for (j = 0; j <= i; j++) {
        cache_real[j] = 0.0f;
        cache_imag[j] = 0.0f;
    }
    for (k = 0; k < K; k++) {
        float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
        float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
        float Bki_real = (((const float *)B)[2 * (k * ldb + i)]);
        float Bki_imag = (((const float *)B)[2 * (k * ldb + i) + 1]);
        float temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        float temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;

        for (j = 0; j <= i; j++) {
            float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            float Bkj_real = (((const float *)B)[2 * (k * ldb + j)]);
            float Bkj_imag = (((const float *)B)[2 * (k * ldb + j) + 1]);

            // Accumulate into local cache instead of directly into global C
            // This removes RAW/WAR dependencies on C across different k values
            float update_real = (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + 
                                (temp2_real * Akj_real - temp2_imag * Akj_imag);
            float update_imag = (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + 
                                (temp2_real * Akj_imag + temp2_imag * Akj_real);

            cache_real[j] += update_real;
            cache_imag[j] += update_imag;
        }
    }
    // After all k iterations, write accumulated result to C — transforms loop-carried partial sums
    for (j = 0; j <= i; j++) {
        (((float *)C)[2 * (i * lda + j)]) += cache_real[j];
        (((float *)C)[2 * (i * lda + j) + 1]) += cache_imag[j];
    }
}
}
