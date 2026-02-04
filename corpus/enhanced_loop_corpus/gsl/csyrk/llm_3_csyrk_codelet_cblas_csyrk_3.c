#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const float *C_ptr = (const float *)C;
float *C_mod = (float *)malloc(2 * ldc * N * sizeof(float));
if (!C_mod) return;
for (int idx = 0; idx < 2 * ldc * N; idx++) {
    C_mod[idx] = C_ptr[idx];
}
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        const int linear_idx = 2 * (ldc * j + i); // Transposed access pattern: symmetric index swap
        const float Cij_real = C_mod[linear_idx];
        const float Cij_imag = C_mod[linear_idx + 1];
        C_mod[linear_idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
        C_mod[linear_idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
// Write back transposed result to original memory layout
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        const int src_idx = 2 * (ldc * j + i);
        const int dst_idx = 2 * (ldc * i + j);
        ((float *)C)[dst_idx]     = C_mod[src_idx];
        ((float *)C)[dst_idx + 1] = C_mod[src_idx + 1];
    }
}
free(C_mod);
}
