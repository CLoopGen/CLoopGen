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
// Variant introducing loop-carried dependency via outer loop fusion
// and changing access pattern to create temporal reuse with partial row-wise update
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {  // Flip triangular iteration: now we traverse by column j, then rows i <= j
        float temp_real = 0.0f;
        float temp_imag = 0.0f;
        for (k = 0; k < K; k++) {
            // Reverse index computation order — still valid due to symmetry in logic
            const float Akj_real = (((const float *)A)[2 * (k * lda + j)]);
            const float Akj_imag = (((const float *)A)[2 * (k * lda + j) + 1]);
            const float Aki_real = (((const float *)A)[2 * (k * lda + i)]);
            const float Aki_imag = (((const float *)A)[2 * (k * lda + i) + 1]);
            // Reorder arithmetic operations slightly (associativity preserved)
            temp_real = temp_real + (Aki_real * Akj_real) - (Aki_imag * Akj_imag);
            temp_imag = temp_imag + (Aki_real * Akj_imag) + (Aki_imag * Akj_real);
        }
        // Update C using same formula, but now the loop-carried dependency on i and j is reversed
        // This changes memory access pattern from row-major-like in original to column-oriented
        int idx = 2 * (i * ldc + j);
        float *Cptr = (float *)C;
        Cptr[idx]   += alpha_real * temp_real - alpha_imag * temp_imag;
        Cptr[idx+1] += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
