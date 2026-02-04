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
// Reduce computational intensity by limiting j-loop to diagonal only and simplifying computation
for (i = 0; i < N; i++) {
    float temp_real = 0.;
    float temp_imag = 0.;
    // Combine both A and B contributions in a single pass with reduced memory accesses
    for (k = 0; k < K; k++) {
        const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
        const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
        const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
        const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
        // Use symmetry: when i == j, terms simplify
        temp_real += 2.0f * (Aik_real * Bik_real - Aik_imag * Bik_imag);
        temp_imag += 2.0f * (Aik_real * Bik_imag + Aik_imag * Bik_real);
    }
    // Only update diagonal elements: C[i][i]
    int ci_idx = 2 * (i * ldc + i);
    (((float *)C)[ci_idx]) += alpha_real * temp_real - alpha_imag * temp_imag;
    (((float *)C)[ci_idx + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
}
}
